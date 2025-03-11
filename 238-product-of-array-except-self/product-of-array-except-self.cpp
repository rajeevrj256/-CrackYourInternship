class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroProd=1;
        int zerocount=0;
        bool zero=false;
        for(int num:nums){
            if(num!=0){
                zeroProd*=num;
            }else if(num==0){
                zero=true;
                zerocount++;
            }
        }

        vector<int>ans(nums.size(),0);
        
        if(zerocount==nums.size()){
            return ans;
        }

        if(zerocount>1){
            zeroProd=0;
        }
        if(zero){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    ans[i]=zeroProd;
                }
            }
        }else{

        
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=0){
                ans[i]=zeroProd/nums[i];
            }
        }
        }
        return ans;
    }
};