class Solution {
public:

    int t[101];
    int help(vector<int>&nums,int index){
        if(index==0)return nums[index];
        if(index<0)return 0;

        if(t[index]!=-1)return t[index];

        int take=nums[index]+help(nums,index-2);
        int skip=help(nums,index-1);

        return t[index]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return help(nums,n-1);
    }
};