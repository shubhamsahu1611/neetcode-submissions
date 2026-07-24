class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            int val=asteroids[i];
            if(val > 0) st.push(val);
            else{
                bool isBurst=false;
                while(!st.empty() && st.top()>0){
                    if(st.top() < abs(val)){
                        st.pop();
                    }
                    else if(st.top()==abs(val)){
                        st.pop();
                        isBurst=true;
                        break;
                    }
                    else{
                        isBurst=true;
                        break;
                    }
                }
                if(!isBurst) st.push(val);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};