class Solution {
public:
    string simplifyPath(string path) {
        stack<string> folders;
        int i=0;
        while(i<path.size()){
            while(i<path.size() && path[i]=='/') i++;
            int cnt=0;
            string dir;
            while(i<path.size() && path[i]!='/'){
                dir.push_back(path[i++]);
            }

            if(dir==".."){
                if(!folders.empty()) folders.pop();
            }
            else{
                // check if all .....
                bool isDot=true;
                for(auto it:dir){
                    if(it!='.') isDot=false;
                }
                if((isDot && dir.size() > 2) || !isDot){
                    folders.push(dir);
                }
            }
            // dir.clear();
            // while(i<path.size() && path[i]!='/' && path[i]!='.'){
            //     dir.push_back(path[i++]);
            // }
            // if(dir.size() > 0) folders.push(dir);
        }
        vector<string> directory;
        while(!folders.empty()){
            directory.push_back(folders.top());
            folders.pop();
        }
        reverse(directory.begin(), directory.end());
        string ans;
        for(int i=0;i<directory.size();i++){
            ans.push_back('/');
            ans.append(directory[i]);
        }
        if(ans.empty()){
            return "/";
        }
        return ans;
    }
};