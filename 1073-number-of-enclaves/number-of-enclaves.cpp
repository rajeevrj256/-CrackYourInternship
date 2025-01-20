class Solution {
public:
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int row,int col){
        vis[row][col]=true;
        int n=grid.size();
        int m=grid[0].size();

        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};

        for(int i=0;i<4;i++){
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]==1){
                dfs(grid,vis,x,y);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(grid,vis,0,j);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(grid,vis,n-1,j);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[j][0]==1 && !vis[j][0]){
                dfs(grid,vis,j,0);
            }
            if(grid[j][m-1]==1 && !vis[j][m-1]){
                dfs(grid,vis,j,m-1);
            }
        }


        int count_move=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count_move++;
                }
            }
        }

        return count_move;


    }
};