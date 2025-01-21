class Solution {
public:
   vector<int>ans;
    bool cyclic(vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&dfsvis,int node){
        if(dfsvis[node])return true;
        if(vis[node])return false;
        
       

        dfsvis[node]=true;

        for(auto i:adj[node]){
            if(cyclic(adj,vis,dfsvis,i)){
                return true;
            }
        }
        dfsvis[node]=false;

        vis[node]=true;
        ans.push_back(node);

        return false;;

        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(const auto& prereq:prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }

        vector<bool>vis(numCourses);
        vector<bool>dfsVis(numCourses);
        
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cyclic(adj,vis,dfsVis,i)){
                    return {};
                }
            }
        }

        return ans;
    }
};