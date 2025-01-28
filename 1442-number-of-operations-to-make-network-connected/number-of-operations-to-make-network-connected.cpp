class DSU{
    public:
    vector<int>rank,parent;
    DSU(int n){
       rank.resize(n,0);
       parent.resize(n);
       for(int i=0;i<n;i++){
        parent[i]=i;
       }
    }

    int find(int node){
        if(parent[node]==node)return node;
        return parent[node]=find(parent[node]);
    }

    void unionSet(int u,int v){
        int find_u=find(u);
        int find_v=find(v);

        if(find_u==find_v)return;

        if(rank[find_u]>rank[find_v]){
            parent[find_v]=find_u;
        }else if(rank[find_v]>rank[find_u]){
            parent[find_u]=find_v;
        }else{
            parent[find_u]=find_v;
            rank[find_v]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int ExtraConnectionEdges=0;
        for(auto it:connections){
            int u=ds.find(it[0]);
            int v=ds.find(it[1]);

            if(u==v){
                ExtraConnectionEdges++;
            }else{
                ds.unionSet(u,v);
            }
        }
        int notConnected=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                 notConnected++;
            }
        }

        int ans=notConnected-1;

        if(ExtraConnectionEdges>=ans)return ans;

        return -1;

    }
};