class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>outdegree(n);
        int i=0;
        
        vector<vector<int>>adj_reverse(n);
        
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                adj_reverse[it].push_back(i);
                outdegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }


        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj_reverse[node]){
                outdegree[it]--;
                if(outdegree[it]==0){
                    q.push(it);
                }
            }

        }
        sort(ans.begin(),ans.end());


        return ans;



    }
};