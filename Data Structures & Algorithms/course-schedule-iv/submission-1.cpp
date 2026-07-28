class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& adj) {
        vector<int> topo;
        vector<int> indegree(numCourses, 0);
        for (auto it : adj) {
            for (auto x : it) indegree[x]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if (topo.size() < numCourses) return {};
        return topo;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<set<int>> desc(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> topo = findOrder(numCourses, adj);
        for (int i = numCourses - 1; i >= 0; i--) {
            cout << topo[i] << " ";
            set<int> st;
            for (auto it : adj[topo[i]]) {
                for (auto x : desc[it]) st.insert(x);
            }
            st.insert(topo[i]);
            desc[topo[i]] = st;
        }
        vector<bool> ans;
        for (auto it : queries) {
            if (desc[it[0]].find(it[1]) != desc[it[0]].end())
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};