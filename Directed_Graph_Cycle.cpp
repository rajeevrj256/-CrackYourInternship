class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[],unordered_map <int,bool>&visited,unordered_map <int,bool>&DFSvisited,int node){
        visited[node]=true;
        DFSvisited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                bool detect=dfs(adj,visited,DFSvisited,i);
                
                if(detect)return 1;
            }else if(DFSvisited[i]){
                return 1;
            }
        }
        DFSvisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map <int,bool>visited;
        unordered_map <int,bool>DFSvisited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=dfs(adj,visited,DFSvisited,i);
                if(ans)return 1;
            }
        }
        return 0;

    }
};
