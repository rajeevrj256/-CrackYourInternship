
class Solution {
  public:
    long long getCount(int n) 
    {
        // Your code goes here
        if(n==1) 
        {
            return 10;
        }

        vector<vector<int>> seen = {
            {0, 8},      //moves from 0
            {1, 2, 4},  
            {2, 1, 3, 5},
            {3, 2, 6},   
            {4, 1, 5, 7},
            {5, 2, 4, 6, 8},
            {6, 3, 5, 9},
            {7, 4, 8},   
            {8, 0, 5, 7, 9},
            {9, 6, 8}    
        };

        vector<vector<long long>> vec(n+1, vector<long long>(10,0));

        for(int i=0;i<10;i++) 
        {
            vec[1][i]=1;
        }

        for(int len=2;len<=n;len++) 
        {
            for(int digit=0;digit<10;++digit) 
            {
                vec[len][digit]=0;
                for(int move:seen[digit]) 
                {
                    vec[len][digit]+=vec[len-1][move];
                }
            }
        }

        long long res=0;
        for(int j=0;j<10;++j) 
        {
            res+=vec[n][j];
        }

        return res;
        
    }
};