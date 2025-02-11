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
        vector<int>prev(m+1,0);
        
        for(int i=1;i<=n;i++){
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++){
                 if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                 }else{
                    curr[j]=max(curr[j-1],prev[j]);
                 }
            }
            prev=curr;
        }
        return prev[m];

        //return help(text1,0,text2,0,dp);
        
    }
};