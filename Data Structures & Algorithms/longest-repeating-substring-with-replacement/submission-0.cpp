class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int len = 0;
        int i = 0;
        int j = 0;
        int max_c = 0;
        int ans = 0;
        map<char, int> cnt;
        while (j < s.size()) {
            char ch = s[j];
            cnt[ch]++;
            len++;
            max_c = max(max_c, cnt[ch]);
            int dist = (len - max_c);
            while (dist > k) {
                char p = s[i];
                cnt[p]--;
                for (auto it : cnt) max_c = max(max_c, it.second);
                len--;
                dist = (len - max_c);
                i++;
            }
            ans = max(ans, len);
            j++;
        }
        return ans;
    }
};
