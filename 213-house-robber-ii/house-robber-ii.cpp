class Solution {
public:
   int solve(vector<int>&nums){
        int prev1=0;
        int prev2=0;

        for(int num:nums){
            int temp=max(prev1,prev2+num);
            prev2=prev1;
            prev1=temp;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
         if(n==1) return nums[0];
  
        vector<int>first(nums.begin(),nums.end()-1);
        vector<int>second(nums.begin()+1,nums.end());
       
        int firstVal=solve(first);
      
        int secondval=solve(second);

        return max(firstVal,secondval);
        
    }
};