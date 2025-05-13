class Solution {
public:
    
    int solve(vector<int>&nums,int index,vector<int>&dp){
        if(index==0)return dp[index]=nums[0];
        if(index<0) return 0;

        if(dp[index]!=-1) return dp[index];

        int skip=solve(nums,index-1,dp);
        int take=nums[index]+solve(nums,index-2,dp);

        return dp[index]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,nums.size()-1,dp);
    }
};