class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        int ans=0;
        int maxi=0;
        unordered_map<char,int>hash;
        for(int r=0;r<s.size();r++){
            hash[s[r]]++;
            maxi=max(maxi,hash[s[r]]);
            if((r-l+1)-maxi>k){
                hash[s[l]]--;
                l++;
            }else{
                ans=max(ans,r-l+1);
            }

        }
        return ans;

    }
};