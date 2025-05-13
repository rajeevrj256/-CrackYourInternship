class Solution {
public:
    unordered_map<int,bool>dp;

    bool canCross(vector<int>& stones,int pos=0,int k=0) {
        //int k=0;
        //int reach=1;
        int key=pos | k<<11 ;

        if(dp.count(key)>0){
            return dp[key];
        }
        for(int i=pos+1;i<stones.size();i++){
             int engery=abs(stones[i]-stones[pos]);
             if(engery<k-1) continue;
             if(engery>k+1) return dp[key]=false;
             if(canCross(stones,i,engery)) return dp[key]=true;


        }

        return dp[key]= (pos==stones.size()-1);
    }
};