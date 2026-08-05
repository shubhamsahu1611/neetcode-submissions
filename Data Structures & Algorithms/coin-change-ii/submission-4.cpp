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
        int n = coins.size();
        memo.assign(n + 1, vector<int>(amount + 5, 0));
        // tabulation
        for (int i = 0; i < n; i++) memo[i][0] = 1;
        for (int target = 1; target <= amount; target++) {
            for (int i = n - 1; i >= 0; i--) {
                memo[i][target] += memo[i + 1][target];
                if (coins[i] <= target) memo[i][target] += memo[i][target - coins[i]];
            }
        }
        return memo[0][amount];
    }
};
