class Solution {
public:
    int help(string & text1,int index1,string text2,int index2,vector<vector<int>>&dp){
       
        if(index1>=text1.size() || index2>=text2.size()) return 0;

        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        if(text1[index1]==text2[index2]){

        return dp[index1][index2]=1+help(text1,index1+1,text2,index2+1,dp);
        }else{
            return dp[index1][index2]=max(help(text1,index1,text2,index2+1,dp),help(text1,index1+1,text2,index2,dp));
        }
        

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
          dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
          dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                 }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                 }
            }
        }
        return dp[n][m];

        //return help(text1,0,text2,0,dp);
        
    }
};