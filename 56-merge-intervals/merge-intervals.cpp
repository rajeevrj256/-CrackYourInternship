class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        vector<vector<int>>ans;

        while(i<n){
            int newstart=intervals[i][0];
            int newend=intervals[i][1];
            

            if(end>=newstart ){
                end=max(newend,end);
               
                
            }

            else{
                ans.push_back({start,end});
                start=newstart;
                end=newend;
            }
            i++;
        }

        ans.push_back({start,end});

        return ans;
    }
};