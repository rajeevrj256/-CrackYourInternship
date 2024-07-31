class Solution {
public:
void backtracking(vector<vector<int>> &ans,vector<int>&res,vector<int>& arr,int index,int sum){
    if(sum==0){
        ans.push_back(res);
        return;
    }

    for(int i=index;i<arr.size();i++){
        if (i > index && arr[i] == arr[i - 1]) continue;
         if (arr[i]>sum) break;

        
        res.push_back(arr[i]);
        backtracking(ans,res,arr,i+1,sum-arr[i]);
        res.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
         sort(candidates.begin(), candidates.end());
        backtracking(ans,res,candidates,0,target);
        return ans;
    }
};