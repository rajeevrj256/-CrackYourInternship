class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(int num:nums){
            q.push(num);
        }

        while(k-->1){
            q.pop();
        }

        return q.top();
    }
};