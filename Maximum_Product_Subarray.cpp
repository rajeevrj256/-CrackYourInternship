class Solution {
public:
    int maxProduct(vector<int>& nums) {
       double maxprod=INT_MIN;
       double prod=1;
       double rev=1;
       for(int i=0;i<nums.size();i++){
           prod=prod*nums[i];
           rev=rev*nums[nums.size()-i-1];
           maxprod=max({prod,rev,maxprod});
        if(prod==0)prod=1;
        if(rev==0)rev=1;
       
       } 
       return maxprod;
    }
};