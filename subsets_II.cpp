class Solution {
public:
   void backtracking(vector<vector<int>>&res,vector<int>&nums,vector<int>&subset,int index){
    if(find(res.begin(),res.end(),subset)==res.end()){
        res.push_back(subset);

    }
    for(int i=index;i<nums.size();i++){
        subset.push_back(nums[i]);
        backtracking(res,nums,subset,i+1);
        subset.pop_back();
    }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>subset;
        sort(nums.begin(), nums.end());
        backtracking(res,nums,subset,0);
        return res;
    }
};