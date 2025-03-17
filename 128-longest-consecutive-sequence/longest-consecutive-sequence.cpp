class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxlen=0;
        int ele=INT_MIN;
        int len=0;

        for(int i=0;i<n;i++){
            if(nums[i]-1==ele){
                len++;
                ele=nums[i];
            }else if(nums[i]!=ele){
                len=1;
                ele=nums[i];
            }

            maxlen=max(maxlen,len);
        }

        
        return maxlen;
    }
};