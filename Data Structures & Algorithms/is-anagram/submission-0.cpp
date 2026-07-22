class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> cnt;
        for(auto it:s) cnt[it]++;
        for(auto it:t) cnt[it]--;
        for(auto it:cnt) if(it.second!=0) return false;
        return true;
    }
};
