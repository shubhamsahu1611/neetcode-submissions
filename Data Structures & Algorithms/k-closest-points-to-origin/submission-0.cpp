class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto it : points) {
            int dis = (it[0] * it[0] + it[1] * it[1]);
            pq.push({dis, it[0], it[1]});
        }
        vector<vector<int>> ans;
        while (k--) {
            vector<int> top = pq.top();
            pq.pop();
            ans.push_back({top[1], top[2]});
        }
        return ans;
    }
};
