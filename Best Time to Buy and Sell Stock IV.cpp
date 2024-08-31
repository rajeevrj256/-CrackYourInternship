class Solution {
public:
    int t[1001][101][2];
    int solve(vector<int>&prices,int opt,int k,int i){
        if(i>=prices.size())return 0;
        if(k==0)return 0;
        int profit=0;

        if(t[i][k][opt]!=-1)return t[i][k][opt];

        if(opt==1){
           profit=max(prices[i]+solve(prices,0,k-1,i+1),solve(prices,1,k,i+1));

        }else{
          profit=max(-prices[i]+solve(prices,1,k,i+1),solve(prices,0,k,i+1));
        }
        return t[i][k][opt]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,k,0);
    }
};