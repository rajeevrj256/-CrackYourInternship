class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<int>prev(2,0);
       vector<int>prev2(2,0);

        for(int i=n-1;i>=0;i--){
            vector<int>curr(2,0);
            for(int j=0;j<=1;j++){
                int skip=prev[j];

                int take=0;

                if(j==0){
                    take=-prices[i]+prev[1];
                }else{
                    
                    take=prices[i]+prev2[0];

                    
                }

                curr[j]=max(take,skip);
            }
            prev2=prev;
            prev=curr;
        }

        return prev[0];

        //return help(prices,0,0,dp);
        
    }
};