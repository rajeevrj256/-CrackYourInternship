class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxarea=INT_MIN;
        while(i<j){
            int len=min(height[i],height[j]);
            int width=(j-i);

            maxarea=max(maxarea,len*width);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
    return maxarea;
    }

};