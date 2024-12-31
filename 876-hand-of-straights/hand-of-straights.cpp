class Solution {
public:
    bool helper(vector<int>&hand,int groupsize,int start,int end){
        int nextele=hand[start]+1;
        hand[start]=-1;
        int i=start+1;
        int grpcount=1;
        
        while(i<end && grpcount<groupsize){
            if(hand[i]==nextele){
                nextele=hand[i]+1;
                
                hand[i]=-1;
                grpcount++;
            }
            i++;

        }
        return (grpcount==groupsize)?true:false;

        
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        sort(hand.begin(),hand.end());

        for(int i=0;i<hand.size();i++){
            if(hand[i]>=0){
                if(!helper(hand,groupSize,i,hand.size())){
                    return false;
                }
            }
        }
        return true;

        
    }
};