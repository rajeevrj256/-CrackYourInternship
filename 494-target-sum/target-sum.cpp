class Solution {
public:
//    int totalsum=0;
//    int solve(vector<int>&arr,int index,int sum,int target,vector<vector<int>>&dp){
    
//     if( index==arr.size()){
//         return (sum==target?1:0);
//     }

//     if(dp[index][sum+totalsum]!=-1)return dp[index][sum+totalsum];



//     int takeplus=solve(arr,index+1,sum+arr[index],target,dp);
//     int takemins=solve(arr,index+1,sum-arr[index],target,dp);


//     return dp[index][sum+totalsum]=takeplus+takemins;



    

//    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>totalsum) return 0;
       vector<int>prev(2*totalsum+1,0);
        
        prev[nums[0]+totalsum]+=1;
        prev[-nums[0]+totalsum]+=1;

        for(int i=1;i<n;i++){
            vector<int>curr(2*totalsum+1,0);
            for(int j=-totalsum;j<=totalsum;j++){
                if (prev[j + totalsum] > 0) {
                curr[j+nums[i]+totalsum]+=prev[j+totalsum];
                curr[j-nums[i]+totalsum]+=prev[j +totalsum];
                }

                //dp[i][j+totalsum]=skip+take;
            }
            prev=curr;
        }

        return prev[target+totalsum];
    }
};