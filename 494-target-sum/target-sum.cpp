class Solution {
public:
   int totalsum=0;
   int solve(vector<int>&arr,int index,int sum,int target,vector<vector<int>>&dp){
    
    if( index==arr.size()){
        return (sum==target?1:0);
    }

    if(dp[index][sum+totalsum]!=-1)return dp[index][sum+totalsum];



    int takeplus=solve(arr,index+1,sum+arr[index],target,dp);
    int takemins=solve(arr,index+1,sum-arr[index],target,dp);


    return dp[index][sum+totalsum]=takeplus+takemins;



    

   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int num:nums){
            totalsum+=num;
        }
        if(abs(target)>totalsum) return 0;
        vector<vector<int>>dp(n,vector<int>(2*totalsum+1,-1));
        return solve(nums,0,0,target,dp);
    }
};