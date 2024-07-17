class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};
