class Solution {
   public:
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& parent) {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (it != parent[node]) {
                parent[it] = node;
                if (vis[it]) return it;
                int ans = dfs(it, adj, vis, parent);
                if (ans != -1) return ans;
            }
        }
        return -1;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n + 1, false);
        vector<int> parent(n + 1, -1);
        int node = dfs(1, adj, vis, parent);
        int curr = node;
        set<vector<int>> cyc;
        while (parent[curr] != node) {
            cyc.insert({min(curr, parent[curr]), max(curr, parent[curr])});
            curr = parent[curr];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (cyc.find(edges[i]) != cyc.end()) return edges[i];
        }
        return {};
    }
};
