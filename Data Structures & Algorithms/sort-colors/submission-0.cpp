class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1;
        int j=0;
        int k=nums.size();
        while(j<k){
            if(nums[j]==1) j++;
            else if(nums[j]==0){
                i++;
                swap(nums[i], nums[j]);
                j++;
            }
            else{
                k--;
                swap(nums[j], nums[k]);
            }
        }
    }
};