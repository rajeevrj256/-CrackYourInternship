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
    if(parent[node]==node) return node;

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
    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size();
       DSU ds(n);

       unordered_map<int,int>rowmap,colmap;

       for(int i=0;i<n;i++){
        int row=stones[i][0];
        int col=stones[i][1];

        if(rowmap.count(row)){
            ds.unionSet(i,rowmap[row]);
            
        }

        if(colmap.count(col)){
            ds.unionSet(i,colmap[col]);
        }


        rowmap[row]=i;
        colmap[col]=i;
       }
       int component=0;
       for(int i=0;i<n;i++){
        if(ds.find(i)==i){
            component++;
        }
       }


       return n-component;
    }
};