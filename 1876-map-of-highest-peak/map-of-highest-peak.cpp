class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>res(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int dx[4]={-1, 0, +1, 0}; 
        int dy[4]= {0, +1, 0, -1}; 

        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int len=q.front().second;
            q.pop();
            res[x][y]=len;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0 && !vis[nx][ny]){

                    q.push({{nx,ny},len+1});
                    vis[nx][ny]=true;
                }
            }
        }
        return res;
    }
};