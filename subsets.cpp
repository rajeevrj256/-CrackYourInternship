class Solution {
public:
    void backtracking (vector<vector<int>>&res,vector<int>&subset,vector<int>&num,int index){
        res.push_back(subset);
        for(int i=index;i<num.size();i++){
            subset.push_back(num[i]);
            backtracking(res,subset,num,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>subset;
        backtracking(res,subset,nums,0);
        return res;
        
    }
};