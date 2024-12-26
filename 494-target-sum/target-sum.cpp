class Solution {
public:
   
   int solve(vector<int>&arr,int index,int sum,int target){
    
    if( index==arr.size()){
        return (sum==target?1:0);
    }

    

    int takeplus=solve(arr,index+1,sum+arr[index],target);
    int takemins=solve(arr,index+1,sum-arr[index],target);


    return takeplus+takemins;



    

   }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        return solve(nums,0,0,target);
    }
};