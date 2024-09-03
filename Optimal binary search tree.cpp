class Solution{
    public:
    
    int optimalSearchTree(int keys[], int freq[], int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> freqSum(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            freqSum[i][i] = freq[i];
            for (int j = i + 1; j < n; j++) {
                freqSum[i][j] = freqSum[i][j - 1] + freq[j];
            }
        }

        for (int length = 1; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;

                for (int r = i; r <= j; r++) {
                    int cost = (r > i ? dp[i][r - 1] : 0) + 
                               (r < j ? dp[r + 1][j] : 0) + 
                               freqSum[i][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};