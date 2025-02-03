class Solution {
public:
    
    int help(vector<int>&nums){
        int prev=nums[0];
        int prev2=0;
        int n=nums.size();
        for(int i=1; i<n; i++){
          int pick = nums[i];
        if(i>1)
            pick += prev2;
        int  nonPick = 0 + prev;
        
         int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
    }
    int rob(vector<int>& nums) {

        if(nums.size()==1)return nums[0];
        vector<int> arr1(nums.begin(), nums.end() - 1);  // Exclude last house
        vector<int> arr2(nums.begin() + 1, nums.end());  // Exclude first house

        

        int ans1=help(arr1);
        int ans2=help(arr2);

        return max(ans1,ans2);
    }
};