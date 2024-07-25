class Solution {
public:
    bool check(vector<int>&nums,int k,int mid){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum<=mid){
                sum+=nums[i];
            }else{
                count++;
                if(count>k)return false;
                sum=nums[i];

            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            s=max(s,nums[i]);
        }
        int e=sum;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;

            if(check(nums,k,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};