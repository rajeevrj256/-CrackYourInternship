class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();

     vector<int>dp(n+1,0);

        for(int i=1;i<=n;i++){
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+dp[j-1];
                }else{
                    curr[j]=max(dp[j],curr[j-1]);
                }
            }
            dp=curr;
        }
        

        return dp[n];
    }
};