class Solution {
public:
    bool solve(string s,vector<string>&words,int index,vector<int>&dp){
        int n=s.length();
        if(index>=s.size()){
            return true;
        }

        if(dp[index]!=-1) return dp[index];
        
        

        for(string word: words){
            int len=word.length();
            if(index+len<=n && word==s.substr(index,len)){
                
                if(solve(s,words,index+len,dp)){
                    return dp[index]=true;
                };
            }
        }
        
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
       

    

        return solve(s,wordDict,0,dp);
    }
};