class Solution {
   public:
    vector<int> dir = {1, 0, -1, 0, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({0, i, j});
            }
        }
        int ans = 0;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int dis = top[0];
            int i = top[1];
            int j = top[2];
            if(vis[i][j]) continue;
            if (grid[i][j] == 0) continue;
            if (grid[i][j] == 1) ans = max(ans, dis);
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k];
                int nj = j + dir[k + 1];
                if (ni >= 0 and nj >= 0 and ni < grid.size() and nj < grid[0].size() &&
                    !vis[ni][nj] && grid[ni][nj] == 1) {
                    q.push({dis + 1, ni, nj});
                }
            }
        }
        // check if any one is still not visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }
        return ans;
    }
};
