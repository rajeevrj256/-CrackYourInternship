class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>> copy = b;

        vector<int>direction={-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 
                int live=0;
                for(int x: direction){
                    for(int y:direction){
                        if(x==0 && y==0){
                        continue;
                        }else {
                            int a=i+x;
                            int b=j+y;
                            if(a>=0 && a<n && b>=0 && b<m && copy[a][b]==1){
                                live++;
                            }
                        }
                    }
                }
                if(copy[i][j]==1 &&(live<2 || live>3)){
                    b[i][j]=0;
                }else if(copy[i][j]==0 && live==3){
                    b[i][j]=1;
                }




            }
        }
    }
};