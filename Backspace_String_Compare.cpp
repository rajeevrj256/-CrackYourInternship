class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string x="",y="";
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='#' and x.size()==0) continue;
            else if(s[i]=='#') x.pop_back();
            else x+=s[i];
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' and y.size()==0) continue;
            if(t[i]=='#') y.pop_back();
            else y+=t[i];
        }
        if(x==y) return true;
        else return false;
    }
};