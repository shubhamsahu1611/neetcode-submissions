class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> cnt;
        for(auto it:nums) cnt[it]++;
        for(auto it:cnt) if(it.second>1) return true;
        return false;
    }
};