class Solution {
public:

    int check(int i,int j,string s){
        int ans=0;
        while(i>=0 && j<=s.size()){
            if(s[i]==s[j]){
            ans++;
            j++;
            i--;
                
            } else{
                break;
            }

        }
        return ans;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=check(i,i,s);
            count+=check(i,i+1,s);
        }

        return count;
    }
};