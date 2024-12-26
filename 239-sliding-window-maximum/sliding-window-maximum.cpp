class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;

        
        for(int i=0;i<nums.size();i++){
               while(!q.empty() && q.top().second<i-k+1){
                q.pop();
               }
               q.push({nums[i],i});
               if (i >= k - 1) {
                ans.push_back(q.top().first);  // The max is always at the top of the heap
            }
        }
    return ans;
    }
};