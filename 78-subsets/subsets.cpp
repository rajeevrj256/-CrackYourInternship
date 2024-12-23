class Solution {
public:
    void backtracking(vector<vector<int>>&ans,vector<int>&res,vector<int>&nums,int index){
               ans.push_back(res);
               for(int i=index;i<nums.size();i++){
                res.push_back(nums[i]);
                backtracking(ans,res,nums,i+1);
                res.pop_back();
               }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>res;
        backtracking(ans,res,nums,0);

        return ans;
        
    }
};