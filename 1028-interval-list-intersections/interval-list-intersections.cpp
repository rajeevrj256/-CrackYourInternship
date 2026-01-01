class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       
    int i=0;
    int j=0;
 int n=firstList.size();
 int m =secondList.size();
 vector<vector<int>>ans;
    while(i<n && j<m){

       int start=max(firstList[i][0],secondList[j][0]);
       int end=min(firstList[i][1],secondList[j][1]);

if(start<=end){
       ans.push_back({start,end});
}
       if(j<m-1 && firstList[i][1]>=secondList[j+1][0]){
        j++;
       }else if (i<n-1 && firstList[i+1][0]<=secondList[j][1]){
        i++;
       }else{
        i++;
        j++;
       }
    }

     return ans;

    }
};