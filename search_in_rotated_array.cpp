
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int flag=-1;
        if(nums[0]==target)flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) flag=i;
        }
        return flag;
        
    }
};