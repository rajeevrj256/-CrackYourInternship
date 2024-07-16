class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(),a.end());
    long long i=0;
    long  j=i+m-1;
    long long  mini=INT_MAX;
    while(j<a.size()){
        mini=min(mini,a[j]-a[i]);
        i++;
        j++;
    }
    return mini;
    
    
    }   
};