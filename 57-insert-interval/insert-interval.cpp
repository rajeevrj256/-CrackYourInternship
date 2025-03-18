class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        for(auto it:intervals){
            q.push(it);
        }

        q.push(newInterval);
        auto it=q.top();
        q.pop();
        int start=it[0];
        int end=it[1];

        while(!q.empty()){
            auto top=q.top();
            q.pop();
            int newstart=top[0];
            int newend=top[1];

            if(end>=newstart){
                end=max(end,newend);
            }else{

            ans.push_back({start,end});
            start=newstart;
            end=newend;
            }

        }
        ans.push_back({start,end});

        return ans;

    }
};