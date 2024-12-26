class Solution {
public:
    string removeleadingzero(string ans){

        
        int i=0;
        while(true){
            if(ans[i]!='0'){
                break;
            }
            i++;
        }
        return i == ans.size() ? "0" : ans.substr(i);
    }
    string removeKdigits(string num, int k) {
        

        if(k==1 && num.size()==1)return "0";
        stack<int>st;
        int i=0;
        for(i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (num[i]-'0')<(num[st.top()]-'0')){
                st.pop();
                k--;

            }
            if(k==0){
                break;
            }
            st.push(i);
        }
         while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
              ans+=num[st.top()];
              st.pop();
        }

        reverse(ans.begin(),ans.end());
        ans+=num.substr(i,num.size());
        if(ans.size()==1)return ans;
        string res=removeleadingzero(ans);

        if(res=="")res="0";
        return res;
    }
};