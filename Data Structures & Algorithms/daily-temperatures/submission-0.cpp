class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> nextGreater(n);
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(st.top()==-1){
                ans[i]=0;
            }
            else ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};
