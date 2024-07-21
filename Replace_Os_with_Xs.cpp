class Solution{
public:


    void dfs( vector<vector<int>>&visited, vector<vector<char>>&mat,vector<int>x,vector<int>y,int row,int col){
        visited[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<4;i++){
            int nrow=row+x[i];
            int ncol=col+y[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(visited,mat,x,y,nrow,ncol);
            }
            
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<int>x={-1,0,1,0};
        vector<int>y={0,1,0,-1};
        
        for(int j=0;j<m;j++){
            if(!visited[0][j] && mat[0][j]=='O'){
                dfs(visited,mat,x,y,0,j);
            }
            if(!visited[n-1][j] && mat[n-1][j]=='O'){
                dfs(visited,mat,x,y,n-1,j);
            }
        }
         for(int i=0;i<n;i++){
            if(!visited[i][0] && mat[i][0]=='O'){
                dfs(visited,mat,x,y,i,0);
            }
            if(!visited[i][m-1] && mat[i][m-1]=='O'){
                dfs(visited,mat,x,y,i,m-1);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};
