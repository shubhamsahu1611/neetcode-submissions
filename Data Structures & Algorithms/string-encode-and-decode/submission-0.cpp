class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s:strs){
            ans.append(to_string(s.length()));
            ans.push_back('#');
            ans.append(s);
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.size()){
            int j=i;
            string l;
            while(s[j]!='#'){
                l.push_back(s[j]);
                j++;
            }
            i=j+1;
            int len=stoi(l);
            string part;
            for(int k=0;k<len;k++){
                part.push_back(s[i++]);
            }
            ans.push_back(part);
        }
        return ans;
    }
};
