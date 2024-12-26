class Solution {
public:
   vector<int>nsl(vector<int>arr,int n){
    stack<int>st;
    vector<int>res(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        res[i]=(st.empty()?-1:st.top());
        st.push(i);
    }

    return res;
   }

   vector<int>nsr(vector<int>arr,int n){
    stack<int>st;
    vector<int>res(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }

        res[i]=(st.empty()?n:st.top());
        st.push(i);
    }
    return res;
   }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left=nsl(heights,n);
        vector<int>right=nsr(heights,n);
        int area=0;
        for(int i=0;i<n;i++){
              
              int width=right[i]-left[i]-1;
              area=max(area,width*heights[i]);
        }

        return area;
        
    }
};