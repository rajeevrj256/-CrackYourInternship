class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int skip=dp[i+1][j];

                int take=0;

                if(j==0){
                    take=-prices[i]+dp[i+1][1];
                }else{
                    if(i+2<n){
                    take=prices[i]+dp[i+2][0];

                    }else{
                        take=prices[i];
                    }
                }

                dp[i][j]=max(take,skip);
            }
        }

        return dp[0][0];

        //return help(prices,0,0,dp);
        
    }
};