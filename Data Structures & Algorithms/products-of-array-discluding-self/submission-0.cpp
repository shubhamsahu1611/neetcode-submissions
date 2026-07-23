class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        int pro=1;
        for(int i=0;i<nums.size();i++){
            pro*=nums[i];
            pre[i]=pro;
        }
        pro=1;
        for(int i=nums.size()-1;i>=0;i--){
            pro*=nums[i];
            suf[i]=pro;
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=(i>0 ? pre[i-1] : 1)*(i<nums.size()-1 ? suf[i+1] : 1);
        }
        return ans;
    }
};
