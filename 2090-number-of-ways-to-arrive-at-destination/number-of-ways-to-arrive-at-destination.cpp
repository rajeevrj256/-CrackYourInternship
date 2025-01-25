class Solution {
public:
int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }

        priority_queue< 
        pair<long ,long>,
        vector<pair<long,long>>,
        greater<pair<long,long>>>q;

        vector<long long>dist(n,LLONG_MAX);
        vector< int>ways(n,0);

        ways[0]=1;
        dist[0]=0;

        q.push({0,0});

        while(!q.empty()){
            auto[steps,node]=q.top();
            q.pop();

            if(steps>dist[node])continue;

            for(auto neighbor:adj[node]){
                long  nextnode=neighbor.first;
                long nextDist=neighbor.second;

                if((nextDist+steps)<dist[nextnode]){
                    dist[nextnode]=(nextDist+steps);
                    q.push({dist[nextnode],nextnode});
                    ways[nextnode]=ways[node];
                }

                else if(nextDist+steps==dist[nextnode]){
                    ways[nextnode]=(ways[node]+ways[nextnode])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};