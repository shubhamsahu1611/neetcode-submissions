class DSU {
   public:
    vector<vector<pair<int, int>>> parent;
    vector<vector<int>> size;
    int comp;
    DSU(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parent.assign(m, vector<pair<int, int>>(n));
        size.assign(m, vector<int>(n, 1));
        comp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) comp++;
                parent[i][j] = {i, j};
            }
        }
    }

    pair<int, int> findParent(int i, int j) {
        if (parent[i][j].first == i and parent[i][j].second == j) return {i, j};
        return parent[i][j] = findParent(parent[i][j].first, parent[i][j].second);
    }

    void Union(int i, int j, int x, int y) {
        pair<int, int> p1 = findParent(i, j);
        pair<int, int> p2 = findParent(x, y);
        if (p1 == p2) return;
        if (size[p1.first][p1.second] > size[p2.first][p2.second]) swap(p1, p2);
        parent[p1.first][p1.second] = p2;
        size[p2.first][p2.second] += size[p1.first][p1.second];
        comp--;
    }
};

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        DSU dsu(grid);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    // go right
                    if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                        dsu.Union(i, j, i, j + 1);
                    }
                    // go down
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                        dsu.Union(i, j, i + 1, j);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) ans = max(ans, dsu.size[i][j]);
            }
        }
        return ans;
    }
};
