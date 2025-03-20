class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>hash;
            hash[s[i]]++;
            int len=1;
            for(int j=i+1;j<s.size();j++){
                if(hash.find(s[j])==hash.end()){
                    len++;
                    hash[s[j]]++;
                    maxlen=max(len,maxlen);

                }else{
                    maxlen=max(len,maxlen);
                    break;
                }
                
            }

        }

        return maxlen;
    }
};