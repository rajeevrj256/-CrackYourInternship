class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int i=1;
        int maxLen=0;
        while(i<n){
            int up=0;
            int down=0;
            while(i<n && arr[i-1]<arr[i]) i++, up++;
            while(i<n && arr[i-1]>arr[i]) i++, down++;

            if(up && down) maxLen=max(maxLen,up+down+1);
            while(i<n && arr[i-1]==arr[i])i++;
        }

        return maxLen;
    }
};