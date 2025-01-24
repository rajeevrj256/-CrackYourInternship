class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int >(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int, pair<int, int>>>>q;
        q.push({0,{0,0}});

        dist[0][0]=0;

        

        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};

        while(!q.empty()){
            int diff=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();

            if(x==n-1 && y==m-1) return diff;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newMaxDiff=max(abs(heights[x][y]-heights[nx][ny]),diff);
                    if(newMaxDiff<dist[nx][ny]){
                        q.push({newMaxDiff,{nx,ny}});
                        dist[nx][ny]=newMaxDiff;
                    }
                }
            }
        }
        return 0;
    }
};