class Solution {
public:
    string simplifyPath(string path) {
        stack <string> str;
        string s;
        for(int i=0;i<path.size();++i){
            if(path[i]=='/'){
                continue;

            }
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                ++i;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!str.empty()){
                    str.pop();
                }
            }
            else{
                    str.push(temp);
            }
        


        }
        while(!str.empty()){
            s="/"+str.top()+s;
            str.pop();
        }
        if(s.size()==0){
            return "/";
        }
        return s;
    }
};