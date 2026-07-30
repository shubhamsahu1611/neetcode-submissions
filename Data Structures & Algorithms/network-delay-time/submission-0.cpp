class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> delay(n + 1, INT_MAX);
        delay[k] = 0;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        vector<bool> vis(n + 1, false);
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            int dis = top.first;
            int u = top.second;
            if (vis[u]) continue;
            vis[u] = true;
            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (!vis[v] && wt + dis < delay[v]) {
                    q.push({wt + dis, v});
                    delay[v] = wt + dis;
                }
            }
        }
        int ans = *max_element(delay.begin() + 1, delay.end());
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
