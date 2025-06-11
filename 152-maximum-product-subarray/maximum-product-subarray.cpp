class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int backProd=1;
        int maxProd=INT_MIN;
        for(int i=0;i<nums.size();i++){

            if(prod==0) prod=1;
             if(backProd==0) backProd=1;
        
             prod=prod*nums[i];
             backProd=backProd*nums[nums.size()-1-i];
             maxProd=max({maxProd,backProd,prod});
             
        }
        return maxProd;
    }
};