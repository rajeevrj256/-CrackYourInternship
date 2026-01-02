class Solution {
public:

    void merge (vector<pair<int,int>>&nums,int start,int end,int mid,vector<int>&ans){
        int i=start;
        int j=mid+1;
        vector<pair<int,int>>res;
        while(i<=mid && j<=end){
           if(nums[i].first<=nums[j].first){
                res.push_back(nums[j]);
                j++;
           }else{
            ans[nums[i].second]+=(end-j+1);
            res.push_back(nums[i]);
            i++;
           }
           
        }

        while(i<=mid){
            res.push_back(nums[i++]);
        }

        while(j<=end){
            res.push_back(nums[j++]);
        }

        for(int k=start;k<=end;k++){
            nums[k]=res[k-start];
        }

        
    }

    void mergeSort(vector<pair<int,int>>&nums,int start,int end,vector<int>&ans){

        if(start>=end) return;

         int mid = start + (end - start) / 2;

         mergeSort(nums,start,mid,ans);
         mergeSort(nums,mid+1,end,ans);
         merge(nums,start,end,mid,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);

        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        mergeSort(arr,0,n-1,ans);

        return ans;
    }
};