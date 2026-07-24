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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long tar=target-nums[i]-nums[j];
                if(tar < -2e9 || tar > 2e9) continue;
                vector<vector<int>> ts=twoSum(nums, tar, j+1, n-1);
                for(auto it:ts){
                    vector<int> tri={nums[i], nums[j], nums[it[0]], nums[it[1]]};
                    sort(tri.begin(), tri.end());
                    st.insert(tri);
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it:st){
            if(target == accumulate(it.begin(), it.end(), 0LL)) ans.push_back(it);
        }
        return ans;
    }
};