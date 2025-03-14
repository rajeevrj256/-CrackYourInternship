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
         if(n==1) return nums[0];
  
        vector<int>first(nums.begin(),nums.end()-1);
        vector<int>second(nums.begin()+1,nums.end());
        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);
        int firstVal=solve(first,dp1,0);
      
        int secondval=solve(second,dp2,0);

        return max(firstVal,secondval);
        
    }
};