class Solution {
public:
    int solve(vector<int>&coins,vector<vector<int>>&dp,int index,int target){
        if(index==0){
            if(target==0) return 1;
            if(target%coins[0]==0) return 1;

            return 0;
        }

        if(dp[index][target]!=-1)return dp[index][target];

        int skip=solve(coins,dp,index-1,target);

        int take=0;
        if(coins[index]<=target){
            take=solve(coins,dp,index,target-coins[index]);
        }

        return dp[index][target]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int totalSum=accumulate(coins.begin(),coins.end(),0);
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,dp,n-1,amount);
    }
};