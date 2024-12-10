class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        
        int maxA=0;
        while(i<j){
           int h=min(height[i],height[j]);
           int w=j-i;
           maxA=max(maxA,h*w);
           if(height[i]<height[j]){
               i++;
               
           }else{
               j--;
           }

        }
        return maxA;
    }
};