class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1=-1;
        int maj2=-1;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1){
                cnt1++;
            }
            else if(nums[i]==maj2){
                cnt2++;
            }
            else if(maj1==-1){
                maj1=nums[i];
                cnt1=1;
            }
            else if(maj2==-1){
                maj2=nums[i];
                cnt2=2;
            }
            else{
                if(cnt1 < cnt2){
                    cnt1--;
                    if(cnt1==0){
                        cnt1++;
                        maj1=nums[i];
                    }
                }
                else{
                    cnt2--;
                    if(cnt2==0){
                        cnt2++;
                        maj2=nums[i];
                    }
                }
            }
        }
        int rc1=0;
        int rc2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1) rc1++;
            else if(nums[i]==maj2) rc2++;
        }
        vector<int> ans;
        if(rc1 > nums.size()/3) ans.push_back(maj1);
        if(rc2 > nums.size()/3) ans.push_back(maj2);
        return ans;
    }
};