class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>adj(n);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        // {stops,{node,price}}
        q.push({0,{src,0}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;

        while(!q.empty()){
               int stop=q.front().first;
               int adjnode=q.front().second.first;
               int price=q.front().second.second;
               q.pop();

               if(stop>k)continue;

               for(auto it:adj[adjnode]){
                  int nextnode=it.first;
                  int nextprice=it.second;
                  if(price+nextprice<dist[nextnode] && stop<=k){
                    q.push({stop+1,{nextnode,price+nextprice}});
                    dist[nextnode]=price+nextprice;
                  }
               } 
        }

        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }

        return dist[dst];
    }
};