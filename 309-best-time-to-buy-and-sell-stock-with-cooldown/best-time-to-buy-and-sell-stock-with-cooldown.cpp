class Solution {
public:
    int help(vector<int>&prices,int index,int action,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;

        int skip=help(prices,index+1,action,dp);
        
        if(dp[index][action]!=-1) return dp[index][action];
        int take=0;
        if(action==0){
            take=-prices[index]+help(prices,index+1,1,dp);
        }else{
            take=prices[index]+help(prices,index+2,0,dp);
        }

        return dp[index][action]=max(skip,take);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        return help(prices,0,0,dp);
        
    }
};