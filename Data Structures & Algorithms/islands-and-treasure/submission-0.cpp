class Solution {
   public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) q.push({0, i, j});
            }
        }
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        while (!q.empty()) {
            vector<int> top = q.front();
            q.pop();
            int dis = top[0];
            int i = top[1];
            int j = top[2];
            if (grid[i][j] == -1 || vis[i][j]) continue;
            grid[i][j] = min(grid[i][j], dis);
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k];
                int nj = j + dir[k + 1];
                if (ni >= 0 and nj >= 0 and ni < grid.size() and nj < grid[0].size() &&
                    !vis[ni][nj] && grid[ni][nj] != -1) {
                    q.push({dis + 1, ni, nj});
                }
            }
        }
    }
};
