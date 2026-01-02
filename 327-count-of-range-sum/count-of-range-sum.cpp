class Solution {
public:
    int  mergeSort(vector<long long>&nums,int start,int end,int lower,int higher){
        if(end-start<=1) return 0;

        int mid=(start+end)/2;

        int count=0;
        count+=mergeSort(nums,start,mid,lower,higher);
        count+=mergeSort(nums,mid,end,lower,higher);


        int lo=start;int ro=start;

        for(int j=mid;j<end;j++){
            while(lo<mid && nums[lo]<(nums[j]-higher)) lo++;
            while(ro<mid && nums[ro]<=(nums[j]-lower)) ro++;
            count+=(ro-lo);
        }

        vector<long long>temp;

        int i=start;
        int j=mid;

        while(i<mid && j<end){
          if(nums[j]>=nums[i]){
            temp.push_back(nums[i]);
            i++;
          }else{
            temp.push_back(nums[j]);
            j++;
          }
        }


        while(i<mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<end){
            temp.push_back(nums[j]);
            j++;
        }

      for (int k = 0; k < temp.size(); k++)
            nums[start + k] = temp[k];
     

     return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
         vector<long long> prefix(n + 1, 0);
         for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, n+1, lower, upper);
    }
};