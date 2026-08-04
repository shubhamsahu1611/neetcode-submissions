class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        int ans = 1;
        int st = 0;
        int end = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j >= n) continue;
                if (s[i] == s[j]) {
                    if (j == i + 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = (dp[i][j] | dp[i + 1][j - 1]);
                    if (dp[i][j] && ans < len) {
                        st = i;
                        end = j;
                    }
                }
            }
        }
        string res(s.begin() + st, s.begin() + end + 1);
        return res;
    }
};
