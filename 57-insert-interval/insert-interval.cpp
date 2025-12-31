class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start=newInterval[0];
        int end=newInterval[1];

vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(start>intervals[i][1]){
                ans.push_back(intervals[i]);
            }
             else if (intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end   = intervals[i][1];
            }else{
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }

           
        }
        
        ans.push_back({start,end});
        return ans;
    }
};