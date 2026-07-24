class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;
        int j = -1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            char val = s[i];
            if (cnt.find(val) != cnt.end()) {
                j = max(j, cnt[val]);
            }
            cnt[val] = i;
            ans = max(ans, i - j);
        }
        return ans;
    }
};
