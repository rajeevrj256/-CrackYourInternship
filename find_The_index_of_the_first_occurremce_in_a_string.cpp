class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        int h=haystack.length();
        if(n>h)return -1;

        if(n==0)return 0;

        for(int i=0;i<h-n+1;i++){
            int j=0;
            while(j<n && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==n)return i;

        }
        return -1;
    }
};