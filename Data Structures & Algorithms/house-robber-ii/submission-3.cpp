class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), (i > 0 ? dp[i - 1] : 0));
        }
        ans = *max_element(dp.begin(), dp.end());
        dp.clear();
        dp.assign(nums.size(), 0);
        int ans2 = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), (i > 0 ? dp[i - 1] : 0));
        }
        ans = max(ans, *max_element(dp.begin(), dp.end()));
        return ans;
    }
};
