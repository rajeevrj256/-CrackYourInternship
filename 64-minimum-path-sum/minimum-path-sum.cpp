class Solution {
public:
    int help(vector<vector<int>>& grid,vector<vector<int>>&dp,int i,int j,int m,int n){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int rightCost=help(grid,dp,i,j+1,m,n);
        int bottomCost=help(grid,dp,i+1,j,m,n);

        return dp[i][j]=grid[i][j]+min(rightCost,bottomCost);


    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return help(grid,dp,0,0,m,n);
    }
};