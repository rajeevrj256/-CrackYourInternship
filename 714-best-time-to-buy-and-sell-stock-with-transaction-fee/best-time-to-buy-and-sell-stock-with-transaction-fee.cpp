class Solution {
public:
int feeTran=0;
int help(vector<int>&prices,int index,int action,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;
        if(dp[index][action]!=-1) return dp[index][action];

        int skip=help(prices,index+1,action,dp);
        
        int take=0;
        if(action==0){
            take=-prices[index]+help(prices,index+1,1,dp);
        }else{
            take=prices[index]-feeTran + help(prices,index+1,0,dp);
        }

        return dp[index][action]=max(skip,take);
    };
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        feeTran=fee;
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return help(prices,0,0,dp);
    }
};