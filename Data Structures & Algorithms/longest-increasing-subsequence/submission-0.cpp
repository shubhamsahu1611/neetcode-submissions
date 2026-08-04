class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int last = -1; last < i; last++) {
                int ind = last + 1;
                if (last == -1) {
                    dp[i][ind] = max(dp[i + 1][ind], 1 + dp[i + 1][i + 1]);
                } else {
                    dp[i][ind] = dp[i + 1][ind];
                    if (nums[i] > nums[last]) dp[i][ind] = max(dp[i][ind], 1 + dp[i + 1][i + 1]);
                }
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};
