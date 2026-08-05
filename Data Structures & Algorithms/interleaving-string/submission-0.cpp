class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (s3.size() != m + n) return false;
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(2, false)));
        dp[n][m][0] = dp[n][m][1] = true;
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (i == n && j == m) continue;
                // when can take s1
                int k = i + j;
                int l = i;
                while (l < n && s1[l] == s3[k]) {
                    l++;
                    k++;
                    dp[i][j][1] = (dp[i][j][1] | dp[l][j][0]);
                }
                // when can take s2
                k = i + j;
                l = j;
                while (l < m && s2[l] == s3[k]) {
                    l++;
                    k++;
                    dp[i][j][0] = (dp[i][j][0] | dp[i][l][1]);
                }
            }
        }
        return (dp[0][0][0] or dp[0][0][1]);
    }
};
