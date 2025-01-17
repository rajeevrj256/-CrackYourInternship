class Solution {
public:
    int count=0;
    void dfs(vector<vector<int>>&adj,unordered_map<int,bool>&vis,int node){
        
        vis[node]=true;
        for(int i=0;i<adj.size();i++){

            if(!vis[i] && adj[node][i]==1){
                dfs(adj,vis,i);
            }
        }
         
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>vis;

        int n=isConnected.size();

        for(int i=0;i<n;i++){
            if(!vis[i]){
        dfs(isConnected,vis,i);
        count++;
                
            }
        }
        return  count;
    }
};