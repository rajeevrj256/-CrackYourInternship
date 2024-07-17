class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        priority_queue<vector<int>>q;
        q.push({p[0][1]-p[0][0],p[0][0]});
        int ans=INT_MIN;
        for(int i=1;i<p.size();i++){
            int x=p[i][0];
            int y=p[i][1];
            while(!q.empty() && x-q.top()[1]>k){
                q.pop();
            }
            if(!q.empty()){
                ans=max(ans,x+y+q.top()[0]);
            }
            q.push({y-x,x});
        }
        return ans;
        
    }
};