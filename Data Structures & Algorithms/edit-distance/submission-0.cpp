class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 5, vector<int>(n + 5, INT_MAX));
        dp[m][n] = 0;
        for (int i = 0; i < m; i++) dp[i][n] = (m - i);
        for (int i = 0; i < n; i++) dp[m][i] = (n - i);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = INT_MAX;
                if (word1[i] == word2[j] && dp[i + 1][j + 1] != INT_MAX)
                    ans = min(ans, dp[i + 1][j + 1]);
                // delete the ith char
                if (dp[i + 1][j] != INT_MAX) ans = min(ans, 1 + dp[i + 1][j]);
                // insert at ith char
                if (dp[i][j + 1] != INT_MAX) ans = min(ans, 1 + dp[i][j + 1]);
                // replace the char
                if (dp[i + 1][j + 1] != INT_MAX) ans = min(ans, 1 + dp[i + 1][j + 1]);
                dp[i][j] = min(dp[i][j], ans);
            }
        }
        return dp[0][0];
    }
};
