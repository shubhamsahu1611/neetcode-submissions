class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            // already bought, 1 case
            // sell
            dp[i][1] = max(dp[i][1], dp[i + 2][0] + prices[i]);
            // don't sell
            dp[i][1] = max(dp[i][1], dp[i + 1][1]);
            // can buy , 0 case
            // buy today
            dp[i][0] = max(dp[i][0], -1 * prices[i] + dp[i + 1][1]);
            // don't buy
            dp[i][0] = max(dp[i][0], dp[i + 1][0]);
        }
        return dp[0][0];
    }
};
