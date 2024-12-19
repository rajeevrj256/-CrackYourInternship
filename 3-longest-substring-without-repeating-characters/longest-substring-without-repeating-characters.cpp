class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        unordered_map<char,int>hash;
        int len=0;
        while(j<n){
            
            if(hash.find(s[j])!=hash.end() && hash[s[j]] >= i){
                i=hash[s[j]]+1;
                
            }
            hash[s[j]]=j;
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};