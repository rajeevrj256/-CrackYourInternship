class Solution {
public:
    int check(int i,int j,string s,int n,int &count){
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--;
            j++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;

        for(int i=0;i<n;i++){
            check(i,i,s,n,count);
            check(i,i+1,s,n,count);

        }

        return count;
    }
};