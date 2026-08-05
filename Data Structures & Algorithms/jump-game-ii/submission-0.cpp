class Solution {
   public:
    int jump(vector<int>& nums) {
        int prev_max = 0;
        int curr_max = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > prev_max) {
                prev_max = curr_max;
                ans++;
            }
            curr_max = max(curr_max, i + nums[i]);
        }
        return ans;
    }
};
