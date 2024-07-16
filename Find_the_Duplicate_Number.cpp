class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int,int>hash;
        for(int i:nums){
            hash[i]++;
            if(hash[i]>1){
                return i;
            }
        }
        return 0;

    }
};