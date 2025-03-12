class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,bool>hash;
        for(int num:nums){
            hash[num]=true;
        }

        for(int i=0;i<=nums.size();i++){
            if(hash.find(i)==hash.end()) return i;
        }

        return 0;

    }
};