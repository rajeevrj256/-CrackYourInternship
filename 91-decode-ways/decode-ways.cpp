class Solution {
public:
    int solve(string s, int index,vector<int>&dp){
        if(index==s.length()) return dp[index]=1;
        if(s[index]=='0') return dp[index]=0;
        if(dp[index]!=-1) return dp[index];


        int processone=solve(s,index+1,dp);
        int processtwo=0;
        if(index+1<s.length()){

        if(s[index]=='1'||( s[index]=='2' && s[index+1]>='0' && s[index+1]<='6' )){
            processtwo=solve(s,index+2,dp);
        }
        }

        return dp[index]=processtwo+processone;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);

        return solve(s,0,dp);
    }
};