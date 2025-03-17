class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfsPacific(vector<vector<int>>&adj,vector<vector<bool>>&vis,int i,int j,int n,int m){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=dx[k]+i;
            int ny=dy[k]+j;

            if(nx>=0 && nx<n && ny>=0 && ny<m  &&  !vis[nx][ny] && adj[nx][ny] >= adj[i][j] ){
                dfsPacific(adj,vis,nx,ny,n,m);
            }
        }

        
        

    }
    void dfsAAtlantic(vector<vector<int>>&adj,vector<vector<bool>>&vis,int i,int j,int n,int m){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=dx[k]+i;
            int ny=dy[k]+j;

            if(nx>=0 && nx<n && ny>=0 && ny<m &&  !vis[nx][ny] && adj[nx][ny] >= adj[i][j] ){
                dfsAAtlantic(adj,vis,nx,ny,n,m);
            }
        }

       
        

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>pracficvis(n,vector<bool>(m,false));
        vector<vector<bool>>atlanticvis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            dfsPacific(heights,pracficvis,i,0,n,m);
        }
        
        for(int i=0;i<m;i++){
            dfsPacific(heights,pracficvis,0,i,n,m);
        }
         for(int i=0;i<n;i++){
            dfsAAtlantic(heights,atlanticvis,i,m-1,n,m);
        }
        
        for(int i=0;i<m;i++){
            dfsAAtlantic(heights,atlanticvis,n-1,i,n,m);
        }


     vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlanticvis[i][j] && pracficvis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;




        
    }
};