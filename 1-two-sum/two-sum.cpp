class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // sort(nums.begin(),nums.end());
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            int remaining=target-nums[i];
            if(hash.find(remaining)!=hash.end()){
                return {i,hash[remaining]};
            }

            hash[nums[i]]=i;
        }

        return {-1,-1};
    }
};