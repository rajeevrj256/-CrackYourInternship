class Solution {
public:
        const int mod=1e9+7;

    long long mypow(long long x,long long n){
        if(n==0){
            return 1;

        }

        if(n%2==0){
            return mypow((x*x)%mod,n/2);
        }else{
            return (x*mypow(x,n-1))%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even=n/2+n%2;
        long long odd=n/2;
        long long epos=mypow(5,even);
        long long opos=mypow(4,odd);
        long long ans=((epos)*(opos))%mod;

        return ans;
    }
};