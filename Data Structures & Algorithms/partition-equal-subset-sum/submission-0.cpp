class Solution {
   public:
    bool solve(int i, int sum, int tsum, vector<int>& nums) {
        if (i == nums.size()) {
            if (2 * sum == tsum) {
                return true;
            }
            return false;
        }
        return (solve(i + 1, sum, tsum + nums[i], nums) ||
                solve(i + 1, sum + nums[i], tsum + nums[i], nums));
    }
    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        vector<bool> dp(tsum / 2 + 5, false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++){
            for(int j=tsum/2+1;j>0;j--){
                if(j>=nums[i]) dp[j]=(dp[j] | dp[j-nums[i]]);
            }
        }
        if(tsum%2==1) return false;
        return dp[tsum/2];
    }
};
