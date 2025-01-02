class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
       
            for(char c:s){
                if(isdigit(c) || isalpha(c)){
                    res+=tolower(c);
                }
            }
        

        string str=res;
        reverse(str.begin(),str.end());

        return str==res;
    }
};