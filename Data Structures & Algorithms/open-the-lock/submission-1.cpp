class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int, string>> q;
        q.push({0, "0000"});
        set<string> bad(deadends.begin(), deadends.end());
        if(bad.find("0000")!=bad.end()) return -1;
        map<string, bool> vis;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int dis = curr.first;
            string s = curr.second;
            if (s == target) return dis;
            if (vis[s]) continue;
            vis[s] = true;
            for (int i = 0; i < 4; i++) {
                // inc
                string ns = s;
                if (s[i] == '9')
                    ns[i] = '0';
                else {
                    ns[i]++;
                }
                if (bad.find(ns) == bad.end()) q.push({dis + 1, ns});
                ns = s;
                // dec
                if (s[i] == '0') {
                    ns[i] = '9';
                } else
                    ns[i]--;
                if (bad.find(ns) == bad.end()) q.push({dis + 1, ns});
            }
        }
        return -1;
    }
};