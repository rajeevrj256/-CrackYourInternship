class Solution {
public:
    void backtracking(string&str,vector<string>&res,int open,int close,int n){
         if(open==n && close==n){
            res.push_back(str);
            return ;
         }

         if(open<n){
            str.push_back('(');
            backtracking(str,res,open+1,close,n);
            str.pop_back();
         }

         if(close<open){
            str.push_back(')');
            backtracking(str,res,open,close+1,n);
            str.pop_back();
         }

        


    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string str="";
        
        backtracking(str,res,0,0,n);

        return res;
    }
};