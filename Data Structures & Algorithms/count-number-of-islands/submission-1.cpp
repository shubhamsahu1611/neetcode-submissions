class Solution {
   public:
    vector<vector<bool>> vis;
    vector<int> dir = {1, 0, -1, 0, 1};
    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;
            if (vis[x][y]) continue;
            vis[x][y] = true;
            for (int k = 0; k < 4; k++) {
                int ni = x + dir[k];
                int nj = y + dir[k + 1];
                if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() &&
                    grid[ni][nj] == '1' && !vis[ni][nj]) {
                    q.push({ni, nj});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vis.assign(grid.size(), vector<bool>(grid[0].size(), false));
        int comp = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    bfs(i, j, grid);
                    comp++;
                }
            }
        }
        return comp;
    }
};
