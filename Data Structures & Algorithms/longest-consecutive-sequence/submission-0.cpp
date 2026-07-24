class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int len=0;
            while(st.find(val)!=st.end()){
                len++;
                st.erase(val);
                val++;
            }
            if(dp.find(val)!=dp.end()){
                len+=(dp[val]);
            }
            dp[nums[i]]=len;
        }
        int ans=0;
        for(auto it:dp) ans=max(ans, it.second);
        return ans;
    }
};
