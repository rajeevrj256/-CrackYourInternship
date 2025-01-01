class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;

        for(int i=0;i<nums.size();i++){
            int remain=target-nums[i];
            if(hash.find(remain)!=hash.end()){
                return {i,hash[remain]};
            }

            hash[nums[i]]=i;
        }

        return {};
        
    }
};