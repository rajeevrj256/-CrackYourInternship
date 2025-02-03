class Solution {
public:
    
    int help(vector<int>&nums,int index,vector<int>&t){
        if(index==0)return nums[0];
        if(index<0)return 0;
        if(t[index]!=-1)return t[index];
        int rob=nums[index]+help(nums,index-2,t);
        int notrob=0+help(nums,index-1,t);

        return t[index]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {

        if(nums.size()==1)return nums[0];
        vector<int> arr1(nums.begin(), nums.end() - 1);  // Exclude last house
        vector<int> arr2(nums.begin() + 1, nums.end());  // Exclude first house

        // DP arrays for both cases
        vector<int> dp1(arr1.size(), -1);
        vector<int> dp2(arr2.size(), -1);

        int ans1=help(arr1,arr1.size()-1,dp1);
        int ans2=help(arr2,arr2.size()-1,dp2);

        return max(ans1,ans2);
    }
};