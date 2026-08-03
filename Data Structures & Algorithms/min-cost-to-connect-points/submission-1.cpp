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
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        for(auto e : edges){
            pq.push({e[0],e[1],e[2]});
        }
        int ans = 0;
        DSU dsu(points.size());
        while(!pq.empty()){
            auto it = pq.top();
            int w = it[0],x = it[1],y = it[2];
            pq.pop();
            if(dsu.find(x) == dsu.find(y)) continue;
            dsu.unite(x,y);
            ans += w;
        }
        // sort(edges.begin(), edges.end());
        // int n = points.size();
        // DSU dsu(n);
        // for (auto it : edges) {
        //     bool isDiff = dsu.unite(it[1], it[2]);
        //     if (isDiff) ans += it[0];
        // }
        return ans;
    }
};
