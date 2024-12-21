class Solution {
public:

    long long  dfs(vector<vector<int>>&adj,vector<int>&values,vector<bool>&vis,int k,int node,int &cnt){
        
        long long  sum=values[node];
        vis[node]=true;

        for(int num:adj[node]){
            if(!vis[num]){
                sum+=dfs(adj,values,vis,k,num,cnt);
            }
        }
        if(sum%k==0){
            cnt++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto & i:edges){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        int cnt=0;
        vector<bool>vis(n,false);
       

            

                dfs(adj,values,vis,k,0,cnt);

            

        

        return cnt;
    }
};