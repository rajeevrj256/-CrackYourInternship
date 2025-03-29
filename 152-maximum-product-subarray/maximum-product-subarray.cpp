class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1;
        int maxProd=INT_MIN;
        int oneMore=1;
        int n=nums.size();
       for(int i=0;i<nums.size();i++){
        

        if(product==0) {
            product=1;
        }

        if(oneMore==0){
            oneMore=1;
        }

        oneMore=oneMore*nums[n-1-i];
        product=product*nums[i];
        maxProd=max({maxProd,product,oneMore});

    
       }
       return maxProd;
    }
};