class Solution {
public:
    void dfs(vector<vector<char>>&grid,int row,int col,vector<vector<bool>>&vis){
        vis[row][col]=true;
        int n=grid.size();
        int m=grid[0].size();

        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};

        for(int i=0;i<4;i++){
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]=='1'){
                dfs(grid,nx,ny,vis);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int land=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    land++;
                }
            }
        }

        return land;
    }
};