class Solution {
public:
    int findGCD(vector<int>& nums) {
         int mini=INT_MAX;
         int maxi=INT_MIN;
         bool found=true;
         for(int num:nums){
            mini=min(num,mini);
            maxi=max(num,maxi);
         }

         int i=mini;

        while(i>0){
            if(mini%i==0 && maxi%i==0) return i;
            
                
            i--;
            
        }
        
        return 1;
    }
};