class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i=0;
        int j=0;
        vector<int > a;
        vector<int > b;
        int n=matrix.size();
        for(i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    a.push_back(i);
                    b.push_back(j);
                    
                    
                }
            }
        }

        for(int i=0;i<a.size();i++){
            int k=a[i];
            for(j=0;j<matrix[k].size();j++){
                matrix[k][j]=0;
            }
        }
        for(int i=0;i<b.size();i++){
            int k=b[i];
            for(j=0;j<matrix.size();j++){
                matrix[j][k]=0;
            }
        }



    }
};