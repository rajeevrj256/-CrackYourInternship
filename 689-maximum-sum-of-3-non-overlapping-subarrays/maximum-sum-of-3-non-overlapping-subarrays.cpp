class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
         vector<int>ans{3,0};
         int n=nums.size();
         vector<int>sums(n-k+1,0);
         vector<int>maxleftsubarry(n-k+1,0);
         vector<int>maxrightsubarry(n-k+1,0);

         int sum=0;
         for(int i=0;i<n;i++){
               sum+=nums[i];
               if(i>=k-1){
                sums[i-k+1]=sum;
                sum-=nums[i-k+1];
               }

         }

         int leftindex=0;
         for(int i=0;i<sums.size();i++){
            if(sums[i]>sums[leftindex]){
                leftindex=i;
            }
            maxleftsubarry[i]=leftindex;
         }
         int rightindex=sums.size()-1;
         for(int i=sums.size()-1;i>=0;i--){
            if(sums[i]>=sums[rightindex]){
                rightindex=i;
            }
            maxrightsubarry[i]=rightindex;
         }
         int maxsum=0;
         for(int i=k;i<sums.size()-k;i++){
            int leftidx=maxleftsubarry[i-k];
            int rightidx=maxrightsubarry[i+k];
            int total=sums[leftidx]+sums[i]+sums[rightidx];
            if(total>maxsum){
                maxsum=total;
                ans={leftidx,i,rightidx};
            }
         }

         return ans;




    }
};