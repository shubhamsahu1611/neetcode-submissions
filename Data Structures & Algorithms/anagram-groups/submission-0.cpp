class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> cnt(strs.size(), vector<int>(26, 0));
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                cnt[i][(strs[i][j]-'a')]++;
            }
        }
        map<vector<int>, vector<int>> ind;
        for(int i=0;i<strs.size();i++){
            ind[cnt[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:ind){
            vector<string> ana;
            for(auto j:it.second){
                ana.push_back(strs[j]);
            }
            ans.push_back(ana);
        }
        return ans;
    }
};
