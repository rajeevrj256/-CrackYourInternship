class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a,a+n);
       sort(b, b + n, greater<int>());
        
        for(int i=0;i<n;i++){
            long long sum=a[i]+b[i];
            if(sum<k)return false;
        }
        return true;
    }
};