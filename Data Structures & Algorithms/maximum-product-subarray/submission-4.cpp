class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 && nums[0] <= 0) return nums[0];
        vector<int> pos(n, 0);
        vector<int> neg(n, 0);
        int prev_pos = 0;
        int prev_neg = 0;
        if (nums[0] > 0)
            prev_pos = nums[0];
        else
            prev_neg = nums[0];
        int ans = prev_pos;
        for (int i = 1; i < n; i++) {
            int curr_pos = 0;
            int curr_neg = 0;
            if (nums[i] > 0) {
                curr_pos = max(nums[i], (prev_pos * nums[i]));
                curr_neg = (prev_neg * nums[i]);
            } else {
                curr_neg = min(nums[i], (prev_pos * nums[i]));
                curr_pos = (prev_neg * nums[i]);
            }
            ans = max(ans, curr_pos);
            prev_pos = curr_pos;
            prev_neg = curr_neg;
        }
        return ans;
    }
};
