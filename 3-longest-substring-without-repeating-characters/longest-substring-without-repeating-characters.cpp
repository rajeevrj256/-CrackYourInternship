class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;

        int n=s.size();
        unordered_map<char,int>hash;
        
        int maxlen=0;
        int len=0;

        while(j<n){
            hash[s[j]]++;

            while(hash[s[j]]>1){
                hash[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;

        }

        return maxlen;
    }
};