class Solution {
   public:
    vector<vector<bool>> vis;
    vector<int> dir = {1, 0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<char>>& board, bool& sur, vector<vector<int>>& nodes,
             int m, int n) {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) sur = false;
        vis[i][j] = true;
        nodes.push_back({i, j});
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];
            if (ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj] and
                board[ni][nj] == 'O') {
                dfs(ni, nj, board, sur, nodes, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vis.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    bool sur = true;
                    vector<vector<int>> nodes;
                    dfs(i, j, board, sur, nodes, m, n);
                    if (sur) {
                        for (auto it : nodes) {
                            board[it[0]][it[1]] = 'X';
                        }
                    }
                }
            }
        }
    }
};
