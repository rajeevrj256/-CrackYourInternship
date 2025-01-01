class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxsum(n,0);
        maxsum[0]=nums[0];

        int maxi=maxsum[0];
        for(int i=1;i<n;i++){
             maxsum[i]=max(maxsum[i-1]+nums[i],nums[i]);
             maxi=max(maxi,maxsum[i]);
        }

        return maxi;
    }
};