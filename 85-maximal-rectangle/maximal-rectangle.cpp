class Solution {
public:

   vector<int>nsl(vector<int>&nums,int n){
    stack<int>st;
    vector<int>res(n,0);
    for(int i=0;i<n;i++){
       while(!st.empty() && nums[i]<=nums[st.top()]){
        st.pop();
       }
       res[i]=(st.empty()?-1:st.top());
       st.push(i);
    }

    return res;
   }
   vector<int>nsr(vector<int>&nums,int n){
    stack<int>st;
    vector<int>res(n,0);
    for(int i=n-1;i>=0;i--){
       while(!st.empty() && nums[i]<=nums[st.top()]){
        st.pop();
       }
       res[i]=(st.empty()?n:st.top());
       st.push(i);
    }
    return res;
   }

    int largestRectangleArea(vector<int>&nums){
       int n=nums.size();
        vector<int>left=nsl(nums,n);
        vector<int>right=nsr(nums,n);
        int area=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            area=max(area,width*nums[i]);
        }
        return area;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m+1,0);
        int area=0;

        for(auto& row:matrix){
            for(int i=0;i<m;i++){
                height[i]=(row[i]=='1'?height[i]+1:0);
            }

            area=max(area,largestRectangleArea(height));
            

        }
        return area;
        
    }
};