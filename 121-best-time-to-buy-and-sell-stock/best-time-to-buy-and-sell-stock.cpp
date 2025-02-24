class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxprofit=0;

        for(int i=1;i<prices.size();i++){
            int sell=prices[i]-buy;
            maxprofit=max(maxprofit,sell);
            buy=min(buy,prices[i]);
        }

        return maxprofit;
    }
};