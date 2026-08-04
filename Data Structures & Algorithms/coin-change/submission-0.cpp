class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 5, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto it : coins) {
                if (i >= it && dp[i - it] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - it]);
            }
        }
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};
