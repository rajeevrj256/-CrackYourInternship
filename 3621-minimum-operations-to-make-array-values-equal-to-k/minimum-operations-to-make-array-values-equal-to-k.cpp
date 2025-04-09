class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        for(int num:nums){
            if(num<k) return -1;
            else if(num>k) hash[num]++;
        }

        return hash.size();
    }
};