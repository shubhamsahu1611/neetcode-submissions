class Solution {
   public:
    int help(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j >= n) continue;
                if (s[i] == s[j]) {
                    if (j == i + 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = (dp[i][j] | dp[i + 1][j - 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++)
                if (dp[i][j]) ans++;
        }
        return ans;
    }
    int countSubstrings(string s) { return help(s); }
};
