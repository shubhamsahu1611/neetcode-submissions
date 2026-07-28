class Solution {
   public:
    void dfs(string node, map<string, vector<string>>& adj, vector<string>& comp,
             map<string, bool>& vis) {
        comp.push_back(node);
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, comp, vis);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, vector<string>> adj;
        map<string, string> name;
        for (auto it : accounts) {
            string n = it[0];
            for (int i = 1; i < it.size() - 1; i++) {
                adj[it[i]].push_back(it[i + 1]);
                adj[it[i + 1]].push_back(it[i]);
                name[it[i]] = n;
            }
            if (it.size() == 2) {
                adj[it[1]] = {};
            }
            name[it.back()] = n;
        }
        map<string, bool> vis;
        vector<vector<string>> ans;
        for (auto it : adj) {
            cout << it.first << endl;
            if (!vis[it.first]) {
                vector<string> comp;
                dfs(it.first, adj, comp, vis);
                vector<string> per;
                per.push_back(name[it.first]);
                sort(comp.begin(), comp.end());
                for (auto x : comp) per.push_back(x);
                ans.push_back(per);
            }
        }
        return ans;
    }
};