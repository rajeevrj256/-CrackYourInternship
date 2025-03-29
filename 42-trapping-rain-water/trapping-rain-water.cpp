class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }

        for(int j=n-2;j>=0;j--){
            right[j]=max(right[j+1],height[j]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];

        }

        return ans;

    }
};