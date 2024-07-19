class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        int i=0;
        int j=0;

        while(j<=s.length()){
            if(j==s.length() || s[j]==' '){
                if(j>i){
                string a=s.substr(i,j-i);

                ans.push_back(a);
                }
                i=j+1;

            }
            j++;
        }
        string res="";
        for(int i=ans.size()-1;i>=0;i--){
            res+=ans[i];
            if(i!=0){

            res+=" ";
            }
            
        }

        return res;
    }
};