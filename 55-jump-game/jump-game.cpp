class Solution {
public:
    bool solve(vector<int>&nums,int index,vector<int>&dp){
        if(index==nums.size()-1) return true;

        if(dp[index]!=-1) return dp[index];
        
        

        for(int i=index+1;i<=index+nums[index];i++){
            if(solve(nums,i,dp)) {
                return dp[index]=true;
            }
        }
        

        return dp[index]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};