class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        for(int i=0;i<s.length();i++){
            if((s[i]=='(') || (s[i]=='{') || (s[i]=='[')){
                v.push(s[i]);
            }
            if(s[i]==')'){
                if(v.empty() || (v.top()!='(' )){
                    return 0;
                }
                else {
                    v.pop();
                    
                }
            }
            else if(s[i]=='}'){
                if(v.empty() || v.top()!='{' ){
                    return 0;
                }
                else {
                    v.pop();
                
                }
            }
            if(s[i]==']'){
                if(v.empty() || v.top()!='[' ){
                    return 0;
                }
                else {
                    v.pop();
                
                }
            }
            
        }
        if(v.empty()==true){
            return 1;
        }
        return 0;
    }
};