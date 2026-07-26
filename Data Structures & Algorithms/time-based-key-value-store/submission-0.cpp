class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int high=mp[key].size()-1;
        int low=0;
        string ans;
        while(low <= high){
            int mid=(low+high)/2;
            if(mp[key][mid].first <= timestamp){
                ans=mp[key][mid].second;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
