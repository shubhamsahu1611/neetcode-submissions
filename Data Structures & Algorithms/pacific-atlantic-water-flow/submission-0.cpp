class Solution {
   public:
    vector<int> dir = {1, 0, -1, 0, 1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(2, false)));
        // 0-> pacific and 1-> atlantic
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            q.push({0, 0, i});
            q.push({1, m - 1, i});
        }
        for (int i = 0; i < m; i++) {
            q.push({0, i, 0});
            q.push({1, i, n - 1});
        }

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int ocean = top[0];
            int i = top[1];
            int j = top[2];
            if (vis[i][j][ocean]) continue;
            vis[i][j][ocean] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k];
                int nj = j + dir[k + 1];
                if (ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj][ocean] and
                    heights[ni][nj] >= heights[i][j]) {
                    q.push({ocean, ni, nj});
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j][0] == 1 and vis[i][j][1] == 1) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
