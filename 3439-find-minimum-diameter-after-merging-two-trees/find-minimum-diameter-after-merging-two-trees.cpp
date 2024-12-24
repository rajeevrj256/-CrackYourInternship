class Solution {
private:
void build(vector<vector<int>>&adj,vector<vector<int>>&edges,int n){
     adj.resize(n);
    for(auto edge:edges){
        int a=edge[0];
        int b=edge[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}

pair<int,int> getdiameter(vector<vector<int>>&adj,int node,int parent){
    int maxdepth1=0;
    int maxdepth2=0;
    int diameter=0;

    for(int neighbor:adj[node]){
        if(neighbor==parent)continue;

        auto [childDiameter,depth]=getdiameter(adj,neighbor,node);

        diameter=max(diameter,childDiameter);
        depth++;

        if(depth>maxdepth1){
            maxdepth2=maxdepth1;
            maxdepth1=depth;
        }else if(depth>maxdepth2){
            maxdepth2=depth;
        }
    }
    
    diameter=max(diameter,maxdepth1+maxdepth2);

    return {diameter,maxdepth1};
}
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;

        vector<vector<int>>adj1;
        vector<vector<int>>adj2;
        build(adj1,edges1,n);
        build(adj2,edges2,m);

        int diameter1=getdiameter(adj1,0,-1).first;
        int diameter2=getdiameter(adj2,0,-1).first;

        int combined_diameter=ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1,diameter2,combined_diameter});



    }
};