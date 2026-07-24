class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> cnt;
        for (auto it : s1) cnt[it]++;
        if (s2.size() < s1.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            cnt[s2[i]]--;
        }
        bool pos = true;
        for (auto it : cnt) {
            if (it.second != 0) pos = false;
        }
        if (pos) return true;
        for (int i = s1.size(); i < s2.size(); i++) {
            cnt[s2[i - s1.size()]]++;
            cnt[s2[i]]--;
            bool pos = true;
            for (auto it : cnt) {
                if (it.second != 0) pos = false;
            }
            if (pos) return true;
        }
        return false;
    }
};
