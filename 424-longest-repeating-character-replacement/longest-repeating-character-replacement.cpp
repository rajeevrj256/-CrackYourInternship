class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxcount=0;
        int maxlen=0;
        unordered_map<char,int>hash;

        while(j<s.size()){;

        hash[s[j]]++;

        maxcount=max(maxcount,hash[s[j]]);

        if((j-i+1)-maxcount>k){
            hash[s[i]]--;
            i++;
        }

        maxlen=max(maxlen,j-i+1);
        j++;
    }

    return maxlen;
}
};