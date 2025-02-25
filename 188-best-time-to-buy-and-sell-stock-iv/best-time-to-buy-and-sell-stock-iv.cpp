class Solution {
public:
    int maxProfit(int r, vector<int>& prices) {
        int n = prices.size();
       
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(r + 1, 0)));
      
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=r;j++){
                for(int k=0;k<=1;k++){
                    int skip=dp[i+1][k][j];
                    int take=0;
                    if(k==0){
                        take=-prices[i]+dp[i+1][1][j];
                    }else{
                        take=prices[i]+dp[i+1][0][j-1];
                    }

                    dp[i][k][j]=max(take,skip);
                }

            }
        }
        return dp[0][0][r];
    
    }
};