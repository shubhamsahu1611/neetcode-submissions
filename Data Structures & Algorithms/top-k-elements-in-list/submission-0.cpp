class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto it:nums) cnt[it]++;
        priority_queue<pair<int, int>> pq;
        for(auto it:cnt) pq.push({it.second, it.first});
        vector<int> ans;
        for(int i=0;i<k;i++){
            pair<int, int> top=pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};
