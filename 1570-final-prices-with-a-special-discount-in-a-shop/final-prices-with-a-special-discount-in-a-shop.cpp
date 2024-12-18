class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            for(;j<n;j++){
                if(prices[j]<=prices[i]){
                    break;
                }
            }
            if(j<n){

            prices[i]=prices[i]-prices[j];
            }
        }

        return prices;
    }
};