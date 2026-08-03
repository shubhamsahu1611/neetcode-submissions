class DSU {
   public:
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return false;
        if (sz[a] > sz[b]) {
            par[b] = a;
            sz[a] += sz[b];
        } else {
            par[a] = b;
            sz[b] += sz[a];
        }
        return true;
    }
};
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
        sort(edges.begin(), edges.end());
        int ans = 0;
        int n = points.size();
        DSU dsu(n);
        for (auto it : edges) {
            bool isDiff = dsu.unite(it[1], it[2]);
            if (isDiff) ans += it[0];
        }
        return ans;
    }
};
