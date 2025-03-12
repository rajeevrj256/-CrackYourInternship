class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int actualsum=n*(n+1)/2;

        int currsum=0;
        for(int num:nums){
            currsum+=num;
        }

        return actualsum-currsum;
    }
};