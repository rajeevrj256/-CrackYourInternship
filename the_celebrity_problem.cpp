class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(mat[a][b]==1){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        int c=s.top();
        s.pop();
        
        for(int i=0;i<n;i++){
            if(i!=c){
                if(mat[i][c]==0 || mat[c][i]==1){
                    return -1;
                }
            }
        }
        return c;
    }
};