class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low <= high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[low] <= nums[high]){
                if(nums[mid] < target) low=mid+1;
                else high=mid-1;
                continue;
            }
            if(nums[mid] >= nums[0]){
                if(target >=nums[0]){
                    if(target < nums[mid]) high=mid-1;
                    else low=mid+1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid] <=nums.back()){
                if(target <=nums.back()){
                    if(target < nums[mid]) high=mid-1;
                    else low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
