class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            cout << vis[i] << " ";
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    vis[top] = true;
                    for (auto it : adj[top]) {
                        if (!vis[it]) {
                            vis[it] = true;
                            q.push(it);
                        }
                    }
                }
                comp++;
            }
        }
        return comp;
    }
};
