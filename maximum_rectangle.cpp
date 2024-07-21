class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>height(m+1,0);
        int area=INT_MIN;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                height[j]=(M[k][j]==1)?height[j]+1:0;
                
                
            }
            
            stack<int>s;
            for(int i=0;i<height.size();i++){
                while(!s.empty() && height[i]<height[s.top()]){
                    int h=height[s.top()];
                    s.pop();
                    int w=s.empty()?i:i-s.top()-1;
                    area=max(area,w*h);
                }
                s.push(i);
            }
        }
        return area;
    }
};