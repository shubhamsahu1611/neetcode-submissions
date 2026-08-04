class Solution {
   public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        // count odd len
        for (int i = 0; i < n; i++) {
            int len = 1;
            int low = i - 1;
            int high = i + 1;
            ans++;
            while (low >= 0 && high < n && s[low--] == s[high++]) {
                len += 2;
                ans++;
            }
        }
        // count even len
        for (int i = 0; i < n; i++) {
            int len = 0;
            int low = i;
            int high = i + 1;
            while (low >= 0 && high < n && s[low--] == s[high++]) {
                len += 2;
                ans++;
            }
        }
        return ans;
    }
};
