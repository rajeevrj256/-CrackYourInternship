class Solution{
public:
    
    bool valid(int i,bool graph[101][101],int m,int n, vector<int> & color,int j){
        for(int k=0;k<n;k++){
            if(k!=i && graph[k][i]==1 && color[k]==j )
            return false;
        }
        return true;
    }
    
    bool solve(int i,bool graph[101][101],int m,int n,vector<int> &color){
        if(i==n)
        return true;
        for(int j=1;j<=m;j++){
            if(valid(i,graph,m,n,color,j))
            {
                color[i]=j;
                if(solve(i+1,graph,m,n,color))
                return true;
                color[i]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
       vector<int> color(n,-1);
        return solve(0,graph,m,n,color);
    }
};