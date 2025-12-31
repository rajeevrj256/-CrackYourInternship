class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=1;
        int remove=0;
        while(j<intervals.size()){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
            }else{
                remove++;
                if(intervals[j][1]<intervals[i][1]){
                    i=j;
                }
            }
            j++;
        }
        return remove;

    }
};