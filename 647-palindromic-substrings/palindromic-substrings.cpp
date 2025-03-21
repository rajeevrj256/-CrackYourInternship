class Solution {
public:
    bool check(string s,int i,int j,vector<vector<int>>&dp){
        if(i>j) return true;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=check(s,i+1,j-1,dp);
        }

        return false;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int len=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                  if(check(s,i,j,dp)){
                    len++;
                  }
            }
        }

        return len;
    }
};