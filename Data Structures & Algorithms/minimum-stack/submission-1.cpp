class MinStack {
public:
    stack<pair<int, int>> st;
    int mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        st.push({val, min(mini, val)});
        mini=min(mini, val);
    }
    
    void pop() {
        st.pop();
        if(!st.empty())mini=st.top().second;
        else mini=INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
