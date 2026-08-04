class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 && nums[0] <= 0) return nums[0];
        vector<int> pos(n, 0);
        vector<int> neg(n, 0);
        if (nums[0] > 0)
            pos[0] = nums[0];
        else
            neg[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = max(nums[i], (pos[i - 1] * nums[i]));
                neg[i] = (neg[i - 1] * nums[i]);
            } else {
                neg[i] = min(nums[i], (pos[i - 1] * nums[i]));
                pos[i] = (neg[i - 1] * nums[i]);
            }
        }
        int ans = *max_element(pos.begin(), pos.end());
        return ans;
    }
};
