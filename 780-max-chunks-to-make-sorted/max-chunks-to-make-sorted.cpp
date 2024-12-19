class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int cnt=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
           arr[i]-=i;
           sum+=arr[i];
           if(sum==0)cnt++;
                   }

        return cnt;
    }
};