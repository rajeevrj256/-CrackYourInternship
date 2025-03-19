class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word, int x,int y,int index,int n,int m,vector<vector<bool>>&vis){
        if(index>=word.size()) return true;
        vis[x][y]=true;
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;

            if(nx>=0 && nx<n && ny>=0 && ny<m &&  !vis[nx][ny] && board[nx][ny]==word[index]){
                if(dfs(board,word,nx,ny,index+1,n,m,vis)){
                    return true;
                }
            }
        }

        vis[x][y]=false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
       
        vector<vector<bool>> vis(n, vector<bool>(m, false));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(board,word,i,j,1,n,m,vis)){
                    return true;
                }
            }
        }


        return false;

        
    }
};