class Solution {
public:
    int addMinimum(string word) {
        int res=0;
        int n=word.size();
        int i=0;
        while(i<n){
            int count=0;
            if(word[i]=='a'){
                count++;
                i++;
            }
            if ( i<n && word[i]=='b'){
                count++;
                i++;
            }

            if(i<n && word[i]=='c'){
                count++;
                i++;
            }
            res+=3-count;


        }
           
        return res;
    }
};