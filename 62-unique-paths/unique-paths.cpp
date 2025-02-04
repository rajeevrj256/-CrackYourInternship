class Solution {
public:
    int help(vector<vector<int>>&dp,int i,int j,int m,int n){
        if(i>=m || j>=n)return 0;
        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];
        
        
           int right=help(dp,i,j+1,m,n);
        

        
            int bottom=help(dp,i+1,j,m,n);
    

        return dp[i][j]=right+bottom;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(dp,0,0,m,n);
        
    }
};