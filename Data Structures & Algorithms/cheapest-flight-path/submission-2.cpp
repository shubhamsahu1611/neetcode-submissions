class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[src][0] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        int iter = 0;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int dis = x[0];
            int node = x[1];
            int stops = x[2];
            if (node == dst) return dis;
            if (stops > k) continue;
            for (auto it : adj[node]) {
                if (it.first == dst) {
                    if ((dist[it.first][stops] > dis + it.second)) {
                        dist[it.first][stops] = dis + it.second;
                        pq.push({dist[it.first][stops], it.first, stops});
                    }
                } else {
                    if ((dist[it.first][stops + 1] > dis + it.second)) {
                        dist[it.first][stops + 1] = dis + it.second;
                        pq.push({dist[it.first][stops + 1], it.first, stops + 1});
                    }
                }
            }
        }
        int ans = *min_element(dist[dst].begin(), dist[dst].begin() + k + 1);
        return ans == 1e9 ? -1 : ans;
    }
};
