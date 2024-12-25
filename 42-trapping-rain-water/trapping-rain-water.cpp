class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int leftmax=0;
        int rightmax=0;
        int trapping=0;
        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>=leftmax){
                    leftmax=height[i];
                }else{
                     trapping+=leftmax-height[i];
                }
                i++;
            }else{
                if(height[j]>=rightmax){
                    rightmax=height[j];
                }else{
                    trapping+=rightmax-height[j];
                }
                j--;
            }
        }
        return trapping;
        
    }
};