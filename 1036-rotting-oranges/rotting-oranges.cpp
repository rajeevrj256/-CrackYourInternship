class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int k=0;
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)k++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }

        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};

        int rotten=0;
        int time=0;

        while(!q.empty()){
            int t=q.size();
            rotten+=t;
            while(t--){
                auto index=q.front();
                q.pop();
                int x=index.first;
                int y=index.second;

                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];

                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1) continue;
                    
                    grid[nx][ny]=2;
                    q.push({nx,ny});


                }
            }
            if(!q.empty())time++;
        }

        return (rotten==k?time:-1);
    }
};