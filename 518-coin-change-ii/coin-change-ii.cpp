class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long>v(amount+1);
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0){
                v[i] = 1; //i / coins[0];
            }
        }
        for(int i=1;i<n;i++){
            vector<long long>curr(amount+1);
            for(int j=0;j<=amount;j++){
                int pick = 0;
                if(coins[i] <= j){
                    pick = curr[j-coins[i]];
                }
                int no_pick = v[j];
                curr[j] = (long)pick+no_pick;
            }
            v = curr;
        }
        return v[amount];
    }
};