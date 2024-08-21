class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char,int>>s;
        for(char c:str){
            if(!s.empty() && s.top().first==c){
                s.top().second++;
            }else{
                s.push({c,1});
            }

            if(s.top().second==k){
                s.pop();

            }
        }
        string res="";
        while(!s.empty()){
            for(int i=0;i<s.top().second;i++){

                 res+=s.top().first;
            }
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};jnu