class Solution {
public:
    int help(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j, int n){
        if(i>=n || j>=n )return INT_MAX;
        if(i==n-1)return triangle[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int bottom=triangle[i][j]+help(triangle,dp,i+1,j,n);
        int bottom_diagonal=triangle[i][j]+help(triangle,dp,i+1,j+1,n);

        return dp[i][j]=min(bottom,bottom_diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
                vector<vector<int>>dp(n,vector<int>(n,-1));
        return help(triangle,dp,0,0,n);
    }
};