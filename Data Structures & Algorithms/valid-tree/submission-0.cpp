class Solution {
   public:
    void dfs(int i, vector<vector<int>>& adj, int& sz, vector<bool>& vis) {
        sz++;
        vis[i] = true;
        for (auto it : adj[i]) {
            if (!vis[it]) dfs(it, adj, sz, vis);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int sz = 0;
        dfs(0, adj, sz, vis);
        if (sz == n and edges.size() == n - 1) return true;
        return false;
    }
};
