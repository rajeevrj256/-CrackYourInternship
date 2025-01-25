class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto time:times){
            adj[time[0]-1].push_back({time[1]-1,time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        q.push({0,k-1});
        while(!q.empty()){
            int steps=q.top().first;
            int node=q.top().second;
            q.pop();

            for(auto i:adj[node]){
                int nextnode=i.first;
                int signal=i.second;
                if(steps+signal<dist[nextnode]){
                    dist[nextnode]=steps+signal;
                    q.push({dist[nextnode],nextnode});
                }
            }
        }

        int mini=0;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) return -1;
            else{
                mini=max(mini,dist[i]);
            }
        }

        return mini;

    }
};