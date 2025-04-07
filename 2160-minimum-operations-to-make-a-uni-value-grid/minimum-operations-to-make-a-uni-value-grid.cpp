class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>grid1;
        for (auto &row:grid){
            for(int num:row){
                grid1.push_back(num);
            }
        }
        
        int mod=grid1[0]%x;

        for(int num:grid1){
            if(num%x!=mod) return -1;
        }

        sort(grid1.begin(),grid1.end());

        int median=grid1[grid1.size()/2];

        int operation=0;

        for(int num:grid1){
            operation+=abs(median-num)/x;
        }

        return operation;
    }
};