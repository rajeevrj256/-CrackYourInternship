class Solution {
public:
   
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

       
        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        for (int j = 0; j <= m; j++) {
        prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    cur[j]=prev[j-1];
                }else{
                    cur[j]=1+min({prev[j],//Deletion
                                   prev[j-1], //replace
                                   cur[j-1]    //insertion    
                                           });
                }
            }
            prev=cur;
        }

        return prev[m];
        
    }
};