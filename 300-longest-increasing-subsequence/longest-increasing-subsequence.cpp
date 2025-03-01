class Solution {
public:
    int help(vector<int>&nums,int prev_index,int index,int len,vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;

        if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];

        int skip=help(nums,prev_index,index+1,len,dp);

        int take=0;

        if(prev_index==-1 || nums[index]>nums[prev_index]){
            take=1+help(nums,index,index+1,len++,dp);
        }

        return dp[index][prev_index+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return help(nums,-1,0,n,dp);
    }
};