class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        //vector<int>leftscore(n);
        int maxscore=0;
        int leftscore=values[0];

        //leftscore[0]=values[0];
        for(int i=1;i<n;i++){
            maxscore=max(maxscore,leftscore+values[i]-i);

            leftscore=max(leftscore,values[i]+i);

        }

        return maxscore;
    }
};