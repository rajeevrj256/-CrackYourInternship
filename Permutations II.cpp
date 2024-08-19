class Solution {
public:
void backtracking(set<vector<int>>&ans,vector<int>&num,int index){
    if(index==num.size()){
    ans.insert(num);
    return;

    }
    for(int i=index;i<num.size();i++){
        swap(num[index],num[i]);
        backtracking(ans,num,index+1);
        swap(num[index],num[i]);
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<bool>used;
        backtracking(ans,nums,0);
        vector<vector<int>> anss(ans.begin(), ans.end());
        return anss;
    }
};