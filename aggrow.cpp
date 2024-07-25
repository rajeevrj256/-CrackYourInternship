class Solution {
public:
    bool check(vector<int> &stalls,int n,int k,int mid){
        int cow=1;
        int lastpos=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-lastpos>=mid){
                lastpos=stalls[i];
                cow++;
            }
        }
        return cow>=k;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s=0;
        int m=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            m=max(m,stalls[i]);
            mini=min(mini,stalls[i]);
            
        }
        int e=m-mini;
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(check(stalls,n,k,mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};