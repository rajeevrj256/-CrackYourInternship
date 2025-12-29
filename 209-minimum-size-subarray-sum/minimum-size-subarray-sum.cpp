class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int minLen=INT_MAX;
         int prefixSum=0;
        while(j<nums.size()){
            prefixSum=prefixSum+nums[j];
            while(prefixSum>=target){
                minLen=min(minLen,j-i+1);
                prefixSum-=nums[i];
                i++;
                 
            }
           

            j++;

        }

        return minLen==INT_MAX?0:minLen;
    }
};