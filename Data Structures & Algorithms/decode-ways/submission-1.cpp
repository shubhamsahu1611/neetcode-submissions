class Solution {
   public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int p1 = 1;
        int p2 = 1;
        for (int i = 1; i < s.size(); i++) {
            int curr = 0;
            if (s[i] == '0') {
                if (s[i - 1] == '0' || (s[i - 1] != '1' && s[i - 1] != '2')) return 0;
                curr = p2;
            } else {
                curr = p1;
                if (s[i - 1] != '0') {
                    string temp(s.begin() + i - 1, s.begin() + i + 1);
                    int val = stoi(temp);
                    if (val <= 26) curr += p2;
                }
            }
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};
