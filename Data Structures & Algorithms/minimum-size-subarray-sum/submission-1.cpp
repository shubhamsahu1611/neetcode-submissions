class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int i = 0;
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        if (tsum < target) return 0;
        int ans = n + 2;
        int j = 0;
        int l = 0;
        while (j < nums.size()) {
            l++;
            while (j < nums.size() && sum < target) {
                sum += nums[j];
                j++;
            }
            if (sum < target) break;
            if (sum >= target) ans = min(ans, j - i);
            while (i < j && sum >= target) {
                ans = min(ans, j - i);
                sum -= nums[i];
                i++;
            }
        }
        return ans;
    }
};