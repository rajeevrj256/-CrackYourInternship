class Solution {
public:
    double helper(double x,long n){
        if(n==0) return 1;
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return helper(x*x, n/2);
        }
        else{
            return x*helper(x, n-1);
        }
    
    };
    double myPow(double x, int n) {
        return helper(x,n);
    }
};