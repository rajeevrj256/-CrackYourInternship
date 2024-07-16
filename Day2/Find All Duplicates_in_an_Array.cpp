class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map <int,int>hash;
        vector<int>ans;
        for(int i:nums){
            hash[i]++;
            if(hash[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};