class Solution {
public:
    bool solve(string s,unordered_map<string,bool>&hash,int index,vector<int>&dp){
        int n=s.length();
        if(index>=s.size()){
            return true;
        }

        if(dp[index]!=-1) return dp[index];
        
        string str= "";

        for(int i=index;i<n;i++){
            str+=s[i];
            if(hash.find(str)!=hash.end()){
                
                if(solve(s,hash,i+1,dp)){
                    return dp[index]=true;
                };
            }
        }
        
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_map<string,bool>hash;

        for(string word:wordDict){
            hash[word]=true;
        }

        return solve(s,hash,0,dp);
    }
};