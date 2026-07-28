class Solution {
   public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
        vis[i] = 1;
        for (auto it : adj[i]) {
            if (vis[it] == 1) return false;
            if (vis[it] == 0) {
                bool ans = dfs(it, adj, vis);
                if (!ans) return false;
            }
        }
        vis[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                bool ans = dfs(i, adj, vis);
                if (!ans) return false;
            }
        }
        return true;
    }
};
