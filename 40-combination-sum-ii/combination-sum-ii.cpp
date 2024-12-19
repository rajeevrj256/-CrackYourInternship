class Solution {
public:
    void backtracking(vector<vector<int>>&ans,vector<int>&res,vector<int>&nums,int index,int target,int sum){
        if(sum>target){
            return ;
        }

        if(sum==target){
            ans.push_back(res);
        }

        for(int i=index;i<nums.size();i++){
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            
            
            
            res.push_back(nums[i]);
            backtracking(ans,res,nums,i+1,target,sum+nums[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(candidates.begin(),candidates.end());

        backtracking(ans,res,candidates,0,target,0);

        return ans;
    }
};