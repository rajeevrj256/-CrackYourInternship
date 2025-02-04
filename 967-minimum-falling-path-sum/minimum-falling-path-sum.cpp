class Solution {
public:
    int help(vector<vector<int>>& matrix,vector<vector<int>>&dp,int i,int j,int n){
        if(j>=n || j<0) return INT_MAX;
        if(i==n-1)return matrix[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int  down=help(matrix,dp,i+1,j,n);
        int  down_left=help(matrix,dp,i+1,j-1,n);
        int  down_right=help(matrix,dp,i+1,j+1,n);

        return dp[i][j]=matrix[i][j]+min({down,down_left,down_right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res=INT_MAX;

        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i-1][j];

                int down_left=matrix[i][j];
                if(j-1>=0){
                    down_left+=dp[i-1][j-1];
                }else{
                    down_left=INT_MAX;
                }

                int down_right=matrix[i][j];

                if(j+1<n){
                    down_right+=dp[i-1][j+1];
                }else{
                    down_right=INT_MAX;
                }

                dp[i][j]=min({down,down_right,down_left});
            }
        }

        for(int i=0;i<n;i++){

        res=min(res,dp[n-1][i]);
        }
        return res;
    }
};