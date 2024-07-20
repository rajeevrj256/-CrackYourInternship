class Solution {
public:
    int solve(vector<int>&nums, int k, vector<int>&dp, int start, int end){
        if(start>end)return 0;
        if (dp[start] != -1){
            return dp[start];
        }
        int ans = INT_MAX;
        int sum = 0;
        for(int i = start; i<=end; i++){
            sum += nums[i];
            if(sum <= k && i == end)return 0;
            if(sum <= k){
                int cal = (k-sum)*(k-sum);
                ans = min(ans , solve(nums, k, dp, i+1, end)+cal);
            }
            sum++;
        }
        return dp[start] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,k,dp,0,n-1);
    } 
};