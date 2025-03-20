class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>hash;
        for(char c:t){
            hash[c]++;
        }

        int count=0;
        int i=0;
        int j=0;
        int minLen=INT_MAX;
        int start=0;
        while(j<s.size()){

            if(hash[s[j]]>0){
                count++;
            }
            hash[s[j]]--;

            while(count==t.size()){
               if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                 hash[s[i]]++;
                 if(hash[s[i]]>0)count--;
                 
                 i++;
            }
            
            j++;
        }

          return (minLen == INT_MAX) ? "" : s.substr(start, minLen);



    }
};