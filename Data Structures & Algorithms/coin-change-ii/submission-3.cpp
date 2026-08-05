class Solution {
   public:
    vector<vector<int>> memo;
    int solve(int target, int i, vector<int>& coins) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (i == coins.size()) return 0;
        if (memo[target][i] != -1) return memo[target][i];
        return memo[target][i] = solve(target, i + 1, coins) + solve(target - coins[i], i, coins);
    }
    int change(int amount, vector<int>& coins) {
        memo.assign(amount + 5, vector<int>(coins.size() + 1, 0));
        int n = coins.size();
        // tabulation
        for (int i = 0; i < n; i++) memo[0][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int target = 1; target <= amount; target++) {
                memo[target][i] += memo[target][i + 1];
                if (coins[i] <= target) memo[target][i] += memo[target - coins[i]][i];
            }
        }
        return memo[amount][0];
    }
};
