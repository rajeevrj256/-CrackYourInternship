class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int prefixSum=0;
        int i=0;
        int j=i+k-1;
        int n=cardPoints.size();

        for(int r=0;r<=j;r++){
            prefixSum+=cardPoints[r];
        }
        
        int maxi=prefixSum;

        j=j+1;
        for(int i=0;i<k;i++){
            prefixSum-=cardPoints[k-1-i];
            prefixSum+=cardPoints[n-1-i];
            
            maxi=max(maxi,prefixSum);



        }
        return maxi;
    }
};