class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;

        }

        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int down=solve(i+1,j,m,n,dp);
        int right=solve(i,j+1,m,n,dp);

        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        //vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    temp[j]=1;
                    continue;
                }
                int right=0;
                int down=0;
                if(i>0){

                right=prev[j];
                }
                if(j>0){

                down=temp[j-1];
                }

                temp[j]=right+down;
            }
            prev=temp;

        }



        return prev[n-1];
        
    }
};