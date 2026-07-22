class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            for(auto s:strs){
                if(i>=s.size()) return ans;
                if(s[i]!=ch) return ans;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};