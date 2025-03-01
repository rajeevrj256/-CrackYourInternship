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
        if(n==0) return 0;
        vector<int>dp(n,1);
        int maxlen=1;
        
        for(int i=1;i<n;i++){
            for(int j=0 ;j<i;j++){
                if(nums[i]>nums[j] ){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        


        return maxlen;
    }
};