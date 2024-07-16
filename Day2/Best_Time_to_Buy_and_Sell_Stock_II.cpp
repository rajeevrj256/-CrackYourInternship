class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                dp[i]=dp[i-1]+(prices[i]-prices[i-1]);
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];




    }
};