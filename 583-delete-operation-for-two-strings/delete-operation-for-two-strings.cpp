class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<int>dp(m+1,0);

        for(int i=1;i<=n;i++){
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+dp[j-1];
                }else{
                    curr[j]=max(curr[j-1],dp[j]);
                }
            }
            dp=curr;
        }
        int l=dp[m];
        int ans=n-l;
        ans+=(m-l);

        return ans;

    }
};