class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;

        for(auto it:strs){
            string st=it;
            sort(it.begin(),it.end());
            hash[it].push_back(st);
        }

        vector<vector<string>>ans;

        for(auto it:hash){
            ans.push_back(it.second);
        }

        return ans;
    }
};