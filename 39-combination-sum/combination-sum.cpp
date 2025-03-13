class Solution {
public:
    void backtracking(vector<vector<int>>&res,vector<int>&ans,vector<int>&candidates,int target,int index){
        if(target==0){
            res.push_back(ans);
            return;
        }

        if(target<0) return ;

        for(int i=index;i<candidates.size();i++){
            ans.push_back(candidates[i]);
            backtracking(res,ans,candidates,target-candidates[i],i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        backtracking(res,ans,candidates,target,0);
        return res;
    }
};