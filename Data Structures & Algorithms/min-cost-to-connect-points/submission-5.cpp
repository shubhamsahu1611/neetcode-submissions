// class DSU {
//    public:
//     vector<int> par, sz;
//     DSU(int n) {
//         par.resize(n);
//         sz.assign(n, 1);
//         for (int i = 0; i < n; i++) {
//             par[i] = i;
//         }
//     }
//     int find(int u) {
//         if (par[u] == u) return u;
//         return par[u] = find(par[u]);
//     }
//     bool unite(int x, int y) {
//         int a = find(x);
//         int b = find(y);
//         if (a == b) return false;
//         if (sz[a] > sz[b]) {
//             par[b] = a;
//             sz[a] += sz[b];
//         } else {
//             par[a] = b;
//             sz[b] += sz[a];
//         }
//         return true;
//     }
// };
class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                edges.push_back(
                    {abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[1]].push_back({e[2], e[0]});
            adj[e[2]].push_back({e[1], e[0]});
        }
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        int ans = 0;
        while (!pq.empty()) {
            auto [w, x] = pq.top();
            pq.pop();
            if (vis[x]) continue;
            vis[x] = true;
            ans += w;
            for (auto it : adj[x]) {
                if (!vis[it.first]) pq.push({it.second, it.first});
            }
        }
        return ans;
    }
};
