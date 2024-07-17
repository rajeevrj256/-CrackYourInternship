class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(i>dp[i-1])return false;
            dp[i]=max(dp[i-1],i+nums[i]);
            
        }
        return dp[n-1]>=n-1;



    }
};