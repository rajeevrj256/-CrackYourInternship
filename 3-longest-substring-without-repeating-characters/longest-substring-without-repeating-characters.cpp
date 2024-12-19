class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        unordered_map<char,int>hash;
        int len=0;
        while(j<n){
            hash[s[j]]++;
            while(hash[s[j]]>1){
                hash[s[i]]--;
                
            i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};