class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<int>ans;
        for(auto num:hash){
            if(num.second>(nums.size()/3)) ans.push_back(num.first);
        }

        return ans;
    }
};