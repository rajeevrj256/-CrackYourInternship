class Solution {
public:
    void check(int i,int j,string s,int n,int & maxlen,int &start){
       
        while(i>=0 && j<n && s[i]==s[j]){
            if(j-i+1>maxlen){
                start=i;
                maxlen=max(maxlen,j-i+1);
            }
            i--;
            j++;
        }
        
    }
    string longestPalindrome(string s) {
        int maxlen=0;
        int start=0;
        for(int i=0;i<s.size();i++){
           check(i,i,s,s.size(),maxlen,start);
            check(i,i+1,s,s.size(),maxlen,start);
        }

        return s.substr(start,maxlen);
    }
};