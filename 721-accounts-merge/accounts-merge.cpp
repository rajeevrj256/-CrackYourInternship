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

    int findPar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findPar(parent[node]);
    }

    void UnionSet(int u,int v){
        int find_u=findPar(u);
        int find_v=findPar(v);

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>hash;
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(hash.find(mail)==hash.end()){
                    hash[mail]=i;
                }else{
                     ds.UnionSet(i,hash[mail]);
                }
            }
        }

       vector<vector<string>> mailbox(n);
        for(auto it:hash){
            string mail=it.first;
            int node=it.second;
            int parent=ds.findPar(node);

            mailbox[parent].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mailbox[i].size()==0)continue;
            sort(mailbox[i].begin(),mailbox[i].end());

            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mailbox[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

    return ans;
    }
};