class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time=0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            auto front=q.front();
            q.pop();
             time=front.first;
            int i=front.second.first;
            int j=front.second.second;
            
            for(auto dir:directions){
                int x=i+dir.first;
                int y=j+dir.second;
                
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 ){
                    q.push({time+1,{x,y}});
                    //ans=time+1;
                    grid[x][y]=2;
                    fresh--;
                }
            }
            
        }
        if(fresh>0)return -1;
        return time;
    }
};