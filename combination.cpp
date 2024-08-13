class Solution {
public:
    void backtracking(vector<int>&number,vector<vector<int>>&res,int index,int k,vector<int>&sub){
        if(sub.size()==k){
            res.push_back(sub);
        }
        for(int i=index;i<number.size();i++){
            sub.push_back(number[i]);
            backtracking(number,res,i+1,k,sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);

        }
        vector<vector<int>>res;
        vector<int>sub;
        backtracking(ans,res,0,k,sub);
        return res;
    }
};