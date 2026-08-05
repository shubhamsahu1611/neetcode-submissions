class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || target < -sum) return 0;
        // ofset by sum
        int n = nums.size();
        vector<vector<int>> dp(2 * sum + 5, vector<int>(nums.size() + 1, 0));
        dp[sum][n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int t = -sum; t <= sum; t++) {
                int t_ind = (t + sum);
                dp[t_ind][i] += (t_ind - nums[i] >= 0 ? dp[t_ind - nums[i]][i + 1] : 0) +
                                (t_ind + nums[i] <= 2 * sum ? dp[t_ind + nums[i]][i + 1] : 0);
            }
        }

        return dp[target + sum][0];
    }
};
