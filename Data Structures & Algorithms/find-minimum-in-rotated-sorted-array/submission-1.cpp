class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=nums[high];
        if(nums[0] < nums.back()){
            return nums[0];
        }
        while(low <= high){
            int mid=(low+high)/2;
            if(nums[mid] >= nums[0]) low=mid+1;
            else if(nums[mid] <= nums.back()) {
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};
