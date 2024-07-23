class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        long long int pro=1;
        long long int zerocount=0;
        for(long long int i :nums){
            if(i!=0){
            pro*=i;
            }else{
                zerocount++;
            }
        }
        vector<long long int>ans(n,0);
        
        for(int i=0;i<n;i++){
            if(zerocount>1){
                ans[i]=0;
            }else if(zerocount==1){
                if(nums[i]!=0){
                    ans[i]=0;
                }else{
                    ans[i]=pro;
                }
            }else{
                ans[i]=pro/nums[i];
            }
        }
        return ans;
    }
};