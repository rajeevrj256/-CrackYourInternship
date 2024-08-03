  public:
    // Function to detect cycle in an undirected graph.
    bool cyclicdfs(unordered_map<int,bool>&visited,vector<int> adj[],int node,int parent){
       // unordered_map <int,int>parent;
       visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                bool detect=cyclicdfs(visited,adj,i,node);
                if(detect)return 1;
            }else if(i!=parent){
                return 1;
            }
        }
        return 0;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
       // unordered_map <int,int>parent;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                
            bool ans=cyclicdfs(visited,adj,i,-1);
            if(ans==1){
                return 1;
            }
            }
        }
        return 0;
        
        
        
        
        
        
        
        
    }
};