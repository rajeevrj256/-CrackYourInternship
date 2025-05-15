class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // qriority_queue<int,vector<int>,greater<int>>q;
        vector<int>merge;
        for(int num:nums1){
            merge.push_back(num);
        }
         for(int num:nums2){
            merge.push_back(num);
        }
       

        int n=merge.size();
       sort(merge.begin(),merge.end());
        if(n%2==0){
              return (merge[n/2-1]+merge[n/2])/2.0;
        }else{
            return merge[n/2];
        }

    }
};