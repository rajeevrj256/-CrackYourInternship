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

            for(int i=0;i<n;i++){
                dp[n-1][i]=triangle[n-1][i];
            }
            for(int i=n-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int down=dp[i+1][j]+triangle[i][j];;
                    int down_diagonal=dp[i+1][j+1]+triangle[i][j];

                    dp[i][j]=min(down,down_diagonal);

                }
            }
        return dp[0][0];
    }
};