class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int curr_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < curr_price) {
                curr_price = prices[i];
            } else {
                pro += (prices[i] - curr_price);
                curr_price = prices[i];
            }
        }
        return pro;
    }
};