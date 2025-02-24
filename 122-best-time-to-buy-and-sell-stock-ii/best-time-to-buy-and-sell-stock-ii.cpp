class Solution {
public:
    int help(vector<int>& prices, int index, int action, vector<vector<int>>& dp) {
        if (index >= prices.size()) return 0; // No more transactions possible

        if (dp[index][action] != -1) return dp[index][action];

        int skip = help(prices, index + 1, action, dp); // Skip the current stock
        int take = 0;

        if (action == 0) { // Buying state
            take = -prices[index] + help(prices, index + 1, 1, dp);
        } else { // Selling state
            take = prices[index] + help(prices, index + 1, 0, dp);
        }

        return dp[index][action] = max(take, skip);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Optimized DP table size

        return help(prices, 0, 0, dp);
    }
};
