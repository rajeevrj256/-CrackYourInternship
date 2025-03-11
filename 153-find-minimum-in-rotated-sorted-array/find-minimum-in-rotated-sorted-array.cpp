class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int start=0;
        int end=n-1;
        int minele=INT_MAX;

        while(start<end){
            int mid=(start+end)/2;
            //minele=min(minele,nums[mid]);

            if(nums[mid]>nums[end] ){
                
                start=mid+1;
            }else{
                end=mid;
                
            }

        }

        return nums[start];
    }
};