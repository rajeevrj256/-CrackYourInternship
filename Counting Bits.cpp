class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        if(n==0)return dp;

        dp[1]=1;
        if(n==1)return dp;
        dp[2]=1;
        if(n==2)return dp;
        int help=2;

        for(int i=3;i<=n;i++){
            if((i&(i-1))==0){
                dp[i]=1;
                help=i;
            }else{
                dp[i]=dp[help]+dp[i%help];
            }

        }
        return dp;
    }
};