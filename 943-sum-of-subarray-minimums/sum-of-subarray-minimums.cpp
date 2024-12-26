class Solution {
public:
    int mod=1e9+7;
    vector<int>getnsl(vector<int>&arr,int n){
        vector<int>res;
        stack<int>st;
        for(int i=0;i<n;i++){
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        return res;
    }
    vector<int>getnsr(vector<int>&arr,int n){
        vector<int>res(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
             while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            res[i]=(st.empty() ? n : st.top());
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl=getnsl(arr,n);
        vector<int>nsr=getnsr(arr,n);
        long long ans=0;

        for(int i=0;i<n;i++){
              long long nslno=i-nsl[i];
              long long nsrno=nsr[i]-i;

              long long ways=nslno*nsrno;

              long long totalsum=(arr[i]*ways)%mod;
              ans=(ans+totalsum)%mod;

        }

        return ans;
    }
};