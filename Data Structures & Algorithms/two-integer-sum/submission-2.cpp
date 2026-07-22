class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr(nums.size());
        for(int i=0;i<nums.size();i++) arr[i]={nums[i], i};
        sort(arr.begin(), arr.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=arr[i].first+arr[j].first;
            if(sum==target) {
               vector<int> ans= {arr[i].second, arr[j].second};
               sort(ans.begin(), ans.end());
               return ans;
                }
            else if(sum<target) i++;
            else j--;
        }
    }
};
