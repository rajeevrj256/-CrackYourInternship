class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return b[1]>a[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int start=intervals[0][0];
        int end=intervals[0][1];

        int i=1;
        int count=0;
        while(i<n){
            int newstart=intervals[i][0];
            int newend=intervals[i][1];

            if(end>newstart){
                count++;
               
              
            }else{

            start=newstart;
            end=newend;
            }
            i++;
        }

        return count;
        


    }
};