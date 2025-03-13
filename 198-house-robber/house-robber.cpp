class Solution {
public:
    int solve(vector<int>&num,vector<int>&dp,int index){
        if(index>=num.size()) return 0;
        if(dp[index]!=-1)return dp[index];
        int skip=solve(num,dp,index+1);
        int take=num[index]+solve(num,dp,index+2);

       
        return dp[index]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);

        return solve(nums,dp,0);
    }
};