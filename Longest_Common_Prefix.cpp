class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        string l=strs[0];
        for(int i=0;i<l.size();i++){
            int j=1;
            for(;j<strs.size();j++){
                if(l[i]!=strs[j][i]){
                    break;
                }
            }
            if(j==strs.size()){
                s+=l[i];
            }else{
                break;
            }
        }
        return s;

    }
};