class Solution {
public:
    
    const int mod=1e9+7;
    int helper(int length,int a, int  b,int low,int high,vector<int>&t){
        if(length>high)return 0;
        int count=0;
        if(length>=low && length<=high){
            count= 1;

        }

        if(t[length]!=-1)return t[length]%mod;
        count= (count+helper(length+a,a,b,low,high,t))%mod;
        count= (count+helper(length+b,a,b,low,high,t))%mod;

         return t[length]=count%mod;


    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int>t(high+1,-1);
       
        return helper(0,zero,one,low,high,t);
    }
};