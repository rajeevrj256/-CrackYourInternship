class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int>nums(m+n);
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                nums[k++]=nums1[i];
                i++;
            }
            else{
                nums[k++]=nums2[j];
                j++;
            }
        }
        while(i<m){
            nums[k++]=nums1[i];
            i++;
        }
        while(j<n){
            nums[k++]=nums2[j];
            j++;
        }
        nums1=nums;
    }
};