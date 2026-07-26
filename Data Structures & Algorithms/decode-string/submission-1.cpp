class Solution {
   public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> count;
        int i = 0;
        while (i < s.size()) {
            // check if no.
            string no;
            while (s[i] <= '9' && s[i] >= '0') {
                no.push_back(s[i++]);
            }
            if (no.size() > 0) {
                int cc = stoi(no);
                count.push(cc);
            }
            if (s[i] == ']') {
                // make string to repeat
                string to_repeat;
                while (st.top() != "[") {
                    string top=st.top();
                    reverse(top.begin(), top.end());
                    to_repeat.append(top);
                    st.pop();
                }
                st.pop();
                reverse(to_repeat.begin(), to_repeat.end());
                int time_to_repeat = count.top();
                count.pop();
                string conc;
                while (time_to_repeat--) {
                    conc.append(to_repeat);
                }
                st.push(conc);
            } else {
                string ss(1, s[i]);
                st.push(ss);
            }
            i++;
        }
        vector<string> temp;
        while (!st.empty()) {
            string bb=st.top();
            reverse(bb.begin(), bb.end());
            temp.push_back(bb);
            st.pop();
        }
        string res;
        for (auto it : temp) {
            res.append(it);
            cout << it << endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};