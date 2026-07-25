class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;
    StockSpanner() {
        st.push(-1);
    }
    
    int next(int price) {
        while(st.top()!=-1 && prices[st.top()]<=price){
            st.pop();
        }
        int ans;
        prices.push_back(price);
        if(st.top()==-1){
            ans=prices.size();
        }
        else{
            ans=prices.size()-st.top()-1;
        }
        st.push(prices.size()-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */