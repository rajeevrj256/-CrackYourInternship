class Solution {
public:
    bool solve(string s,string p){
        if(p.length()==0){
            if(s.length()==0) return true;

            return false;
        }

       bool isFirstCharMatch=!s.empty() && (s[0]==p[0] || p[0]=='.');
        if(p.length()>=2 && p[1]=='*'){
            bool not_take=solve(s,p.substr(2));
            bool take=(isFirstCharMatch)&& solve(s.substr(1),p);
            return not_take || take;
        }else{
            return isFirstCharMatch && solve(s.substr(1),p.substr(1));
        }
    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};