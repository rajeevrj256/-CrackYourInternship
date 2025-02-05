class Solution {
public:

    bool help(vector<int>&nums,vector<vector<int>>&dp,int index,int target){

        if(target==0)return true;
        if(index>=nums.size() || target<0) return false;

        if(dp[index][target]!=-1)return dp[index][target];

        bool take=help(nums,dp,index+1,target-nums[index]);
        bool skip=help(nums,dp,index+1,target);

        return dp[index][target]=take|| skip;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();

        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0)return false;
        int target=sum/2;

        
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));

        return help(nums,dp,0,sum/2);
    }
};