class Solution {
   public:
    vector<vector<int>> twoSum(vector<int>& numbers, int target, int st, int end) {
        int low = st;
        int high = end;
        vector<vector<int>> ans;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                ans.push_back({low, high});
                low++;
                high--;
            } else if (sum < target)
                low++;
            else
                high--;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = (-1 * nums[i]);
            vector<vector<int>> ts = twoSum(nums, target, i + 1, nums.size() - 1);
            for (auto p : ts) {
                vector<int> tri = {nums[i], nums[p[0]], nums[p[1]]};
                sort(tri.begin(), tri.end());
                st.insert(tri);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
