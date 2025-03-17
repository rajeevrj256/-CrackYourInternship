class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j,int n,int m){
        vis[i][j]=true;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
           int nx=dx[k]+i;
           int ny=dy[k]+j;
           
           if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='1'){
            dfs(grid,vis,nx,ny,n,m);
           }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,i,j,n,m);
                    count++;
                }
            }
        }

        return count;
    }
};