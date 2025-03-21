class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>hash;
        priority_queue<pair<int,int>>q;
        for(int num:nums){
            hash[num]++;

            
        }

        for(auto it:hash){
            q.push({it.second,it.first});
        }

        while(k>0){
            pair<int,int>pr=q.top();
            q.pop();

            ans.push_back(pr.second);
            k--;
        }

        return ans;
    }
};