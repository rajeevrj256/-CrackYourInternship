class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }

        while(k>0){
            pair<int,int>front=q.top();
            q.pop();
            nums[front.second]=nums[front.second]*multiplier;

            q.push({nums[front.second],front.second});
            k--;
        }

        return nums;
    }
};