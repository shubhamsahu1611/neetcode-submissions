class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), (i > 0 ? dp[i - 1] : 0));
        }
        return dp.back();
    }
};
