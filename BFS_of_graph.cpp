class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        unordered_map <int,bool>visted;
        queue<int>q;
        
        q.push(0);
        visted[0]=true;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            int size=adj[front].size();
            
            for(int i=0;i<size;i++){
                int val=adj[front][i];
                if(!visted[val]){
                    q.push(val);
                    visted[val]=true;
                }
            }
        }
        return ans;
    }
};