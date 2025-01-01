class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>hash;
        for(int num:nums){
            hash.insert(num);
        }

        for(int i=0;i<nums.size();i++){
            if(hash.find(i)==hash.end())return i;
        }

        return nums.size();
    }
};