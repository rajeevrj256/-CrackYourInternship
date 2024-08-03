// User function template for C++

class Solution {
  public:
    void backtracking(vector<vector<int>> &mat,vector<string>&ans,string str,int n,int row,int col){
        if(row>=n || col>=n || row<0 || col<0 || mat[row][col]==0){
            return;
        }
        
        if(row==n-1 && col==n-1){
            ans.push_back(str);
            return;
        }
        
        
        mat[row][col]=0;
        backtracking(mat,ans,str+"U",n,row-1,col);
        backtracking(mat,ans,str+"R",n,row,col+1);
        backtracking(mat,ans,str+"L",n,row,col-1);
        backtracking(mat,ans,str+"D",n,row+1,col);
        mat[row][col]=1;
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        string str="";
        int n=mat.size();
        backtracking(mat,ans,"",n,0,0);
        return ans;
    }
};