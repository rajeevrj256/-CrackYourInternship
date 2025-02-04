class Solution {
public:
    int help(vector<vector<int>>& arr,vector<vector<int>>& dp,int i,int j,int m,int n){
        if(i>=m || j>=n || arr[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        int bottom=help(arr,dp,i+1,j,m,n);
        int right=help(arr,dp,i,j+1,m,n);

        return dp[i][j]=bottom+right;

        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return help(obstacleGrid,dp,0,0,m,n);
    }
};