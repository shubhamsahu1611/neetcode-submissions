class Solution {
   public:
    int help(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), (i > 0 ? dp[i - 1] : 0));
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        vector<int> temp1(nums.begin() + 1, nums.end());
        vector<int> temp2;
        if (nums.size() > 3)
            temp2.assign(nums.begin() + 2, nums.end() - 1);
        else
            temp2 = {};
        return max(nums[0] + help(temp2), help(temp1));
    }
};
