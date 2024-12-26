class Solution {
public:
   int t[1000][2001];
   int solve(vector<int>&arr,int index,int sum,int target){
    
    if( index==arr.size()){
        return (sum==target?1:0);
    }

    if(t[index][sum+1000]!=-1)return t[index][sum+1000];

    int takeplus=solve(arr,index+1,sum+arr[index],target);
    int takemins=solve(arr,index+1,sum-arr[index],target);


    return t[index][sum+1000]=takeplus+takemins;



    

   }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,target);
    }
};