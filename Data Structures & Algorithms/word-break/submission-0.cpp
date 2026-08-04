class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int maxL = 0;
        for (auto it : wordDict) maxL = max(maxL, (int)it.size());
        set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n, false);
        for (int i = 0; i < n; i++) {
            if (i == 0 || dp[i - 1]) {
                string curr;
                int j = i;
                while (j < n && curr.size() < maxL) {
                    curr.push_back(s[j]);
                    if (st.find(curr) != st.end()) {
                        dp[j] = true;
                    }
                    j++;
                }
            }
        }
        return dp[n - 1];
    }
};
