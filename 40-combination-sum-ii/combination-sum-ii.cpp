class Solution {
public:
    void backtracking(vector<vector<int>>&ans,vector<int>&res,vector<int>&nums,int index,int target){
        

        if(target==0){
            ans.push_back(res);
        }

        for(int i=index;i<nums.size();i++){
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            if(target<0){
                break;
            }
            
            
            
            res.push_back(nums[i]);
            backtracking(ans,res,nums,i+1,target-nums[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(candidates.begin(),candidates.end());

        backtracking(ans,res,candidates,0,target);

        return ans;
    }
};