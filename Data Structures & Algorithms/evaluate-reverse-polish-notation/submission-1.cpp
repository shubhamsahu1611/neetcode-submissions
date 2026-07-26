class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            string s=tokens[i];
            if(s=="+"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                a=(a+b);
                st.push(a);
            }
            else if(s=="-"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                a=(a-b);
                st.push(a);
            }
            else if(s=="*"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                a=(a*b);
                st.push(a);
            }
            else if(s=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                a=(a/b);
                st.push(a);
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
