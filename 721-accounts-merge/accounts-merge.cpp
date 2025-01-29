class Solution {
public:
    unordered_map<string,vector<string>>adj;
    unordered_set<string>vis;
    vector<vector<string>>ans;
    void dfs(string email){
        vis.insert(email);
        ans.back().push_back(email);
        for(auto it:adj[email]){
            if(!vis.count(it)){
                dfs(it);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       
        for(auto it:accounts){
            for(int i=2;i<it.size();i++){
                adj[it[i]].push_back(it[i-1]);
                adj[it[i-1]].push_back(it[i]);
            }
        }

        
        for(auto it:accounts){
            if(!vis.count(it[1])){
                ans.push_back({it[0]});
                dfs(it[1]);
                sort(begin(ans.back())+1,end(ans.back()));


            }
        }

        return ans;
    }
};