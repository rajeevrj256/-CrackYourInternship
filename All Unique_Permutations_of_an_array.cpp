class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        ans.push_back(arr);
        while(next_permutation(arr.begin(),arr.end())){
            vector<int>cc;
            for(int i=0;i<n;i++){
                cc.push_back(arr[i]);
            }
            ans.push_back(cc);
        }
        return ans;
    }
};