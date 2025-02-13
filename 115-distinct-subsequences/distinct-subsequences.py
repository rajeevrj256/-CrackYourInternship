class Solution:
    def solve(self,s:str,i:int,t:str,j:int,dp:list[list[int]]) ->int:
        if j<0:
            return 1
        if i<0:
            return 0

        if dp[i][j]!=-1:
            return dp[i][j]

        res=0
        if s[i]==t[j]:
            res=self.solve(s,i-1,t,j-1,dp)+self.solve(s,i-1,t,j,dp)
        else:
            res=self.solve(s,i-1,t,j,dp)

        dp[i][j]=res
        return  dp[i][j]
    def numDistinct(self, s: str, t: str) -> int:
        n=len(s)
        m=len(t)

        dp=[[-1]*(m) for _ in range(n)]
        ans=self.solve(s,n-1,t,m-1,dp)
        return ans 

        