class Solution {
public:
 string s;
    string p;
    vector<vector<int>>dp;
    bool solve(int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool ans;

        if(j==p.length()){
            return dp[i][j]= (i==s.length());
        }else{
             bool firstMatchChar=(i<s.length() && (s[i]==p[j] || p[j]=='?'));

            if(j<p.length() && p[j]=='*'){
           

            bool not_take=solve(i,j+1);

           bool take = (i < s.length()) && solve(i+1, j);
            ans=take || not_take;
            }else{
              ans= firstMatchChar && solve(i+1,j+1);
            }
        }


        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
          this->p=p;
        this->s=s;
        dp.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solve(0,0);
    }
};