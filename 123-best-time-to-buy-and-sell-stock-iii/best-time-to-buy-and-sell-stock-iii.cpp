class Solution {
public:
    int help(vector<int>& prices, int index, int action,int k, vector<vector<vector<int>>>& dp) {
        if (index >= prices.size() || k==0 ) return 0;

        if (dp[index][action][k] != -1) return dp[index][action][k];

        int skip = help(prices, index + 1, action, k,dp); 
        int take = 0;

        if (action == 0) { // Buying state
            take = -prices[index] + help(prices, index + 1, 1,k, dp);
        } else { // Selling state
            take = prices[index] + help(prices, index + 1, 0,k-1, dp);
        }

        return dp[index][action][k] = max(take, skip);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n, vector<int>(2, -1)); 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2 + 1, -1)));

        return help(prices, 0, 0,2, dp);
    }
};