class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int n=nums.size();
        int currSum=nums[0];
        for(int i=1;i<n;i++){
            currSum=max(currSum+nums[i],nums[i]);
            maxSum=max(currSum,maxSum);
            //currSum=maxSum;
        }

        return maxSum;
    }
};