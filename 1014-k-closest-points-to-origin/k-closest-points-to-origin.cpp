class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>q;
        int i=0;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            int distance=(x*x + y*y);
            q.push({distance,i});
            i++;
            if(q.size()>k){
                q.pop();
            }
        }

        vector<vector<int>>ans;
        while(!q.empty()){
            auto [dist,index]= q.top();
            q.pop();

            ans.push_back(points[index]);
        }

        return ans;
    }
};