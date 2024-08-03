class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(vector<int>&ans,vector<int> adj[],int node,unordered_map<int,bool>&visited){
        if(!visited[node]){
            visited[node]=true;
            ans.push_back(node);
            for(auto i:adj[node]){
                dfs(ans,adj,i,visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        unordered_map<int,bool>visited;
        dfs(ans,adj,0,visited);
        return ans;
        
    }
};