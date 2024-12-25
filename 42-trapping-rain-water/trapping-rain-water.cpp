class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int>s;
        int trapping=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && height[i]>height[s.top()]){
                int top=s.top(); // bottom index;
                s.pop();
                if(s.empty())break; // no left boundaries;

                int left=s.top();
                
                int width=i-left-1;
                int hight=min(height[left],height[i])-height[top];

                trapping+=(width*hight);

            }
            s.push(i);
        }
        return trapping;
    }
};