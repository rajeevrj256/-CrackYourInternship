class Solution {
public:
    void backtrack(vector<vector<int>>&ans,vector<int>&res,int k,int n,int index,int sum){
        if(res.size()==k and sum==n){
            ans.push_back(res);
        }

        for(int i=index;i<=9;i++){
            sum+=i;
            res.push_back(i);
            backtrack(ans,res,k,n,i+1,sum);
            sum-=i;
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>res;
        backtrack(ans,res,k,n,1,0);

        return ans;
    }
};