class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    // Code here
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    queue<pair<pair<int,int>,int>>q;
	    int dirx[8]={2,1,2,-1,-2,-2,-1,1};
	    int diry[8]={-1,2,1,2,1,-1,-2,-2};
	    q.push({{k[0],k[1]},0});
	    
	    while(!q.empty()){
	        int x=q.front().first.first;
	         int y=q.front().first.second;
	          int k=q.front().second;
	          q.pop();
	          if(x==t[0] && y==t[1]){
	              return k;
	          }
	          
	          for(int i=0;i<8;i++){
	              int nx=x+dirx[i];
	              int ny=y+diry[i];
	              
	              if(nx>0 && nx<=N && ny>0 && ny<=N){
	                  if(vis[nx][ny]==0){
	                      vis[nx][ny]=1;
	                      q.push({{nx,ny},k+1});
	                  }
	              }
	          }
	        
	        
	    }
	    return -1;
	}
};
