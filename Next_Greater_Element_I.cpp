class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        int n=num2.size();
        vector<int>ans(num1.size());
        stack<int>s;
        unordered_map<int,int>m;
        for(int num:num2){
            while(!s.empty() && s.top()<num){
                m[s.top()]=num;
                s.pop();
            }

            s.push(num);
        }
            while(!s.empty()){
                m[s.top()]=-1;
                s.pop();
            }
        
        for(int i=0;i<num1.size();i++){
            ans[i]=m[num1[i]];
        }

        return ans;
        


        
    }
};