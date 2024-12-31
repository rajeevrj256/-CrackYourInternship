class Solution {
public:
    // bool helper(vector<int>&hand,int groupsize,int start,int end){
    //     int nextele=hand[start]+1;
    //     hand[start]=-1;
    //     int i=start+1;
    //     int grpcount=1;
        
    //     while(i<end && grpcount<groupsize){
    //         if(hand[i]==nextele){
    //             nextele=hand[i]+1;
                
    //             hand[i]=-1;
    //             grpcount++;
    //         }
    //         i++;

    //     }
    //     return (grpcount==groupsize)?true:false;

        
    // }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
         map<int,int>minheap;

         for(int i=0;i<hand.size();i++){
            minheap[hand[i]]++;
         }

         while(!minheap.empty()){
            int currCard=minheap.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(minheap[currCard+i]==0){
                    return false;
                }
                minheap[currCard+i]--;
                if(minheap[currCard+i]<1){
                    minheap.erase(currCard+i);
                }
            }
         }
        return true;

        
    }
};