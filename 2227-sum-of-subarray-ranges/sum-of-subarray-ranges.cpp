class Solution {
public:

    vector<int>nextSmallerLeft(vector<int>&nums,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
              while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
              }

              res[i]=(st.empty()?-1:st.top());
              st.push(i);
        }

        return res;

    }

    vector<int>nextSmallerRight(vector<int>&nums,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            res[i]=(st.empty()?n:st.top());
            st.push(i);
        }

        return res;

    }

    vector<int>nextLargestLeft(vector<int>&nums,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
              while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
              }

              res[i]=(st.empty()?-1:st.top());
              st.push(i);
        }

        return res;

    }

    vector<int>nextLargestRight(vector<int>&nums,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
              while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
              }
              res[i]=(st.empty()?n:st.top());
              st.push(i);
        }

        return res;

    }


    



    
    long long subArrayRanges(vector<int>& nums) {
         int n=nums.size();
        vector<int>nsl=nextSmallerLeft(nums,n);
        vector<int>nsr=nextSmallerRight(nums,n);
        
        vector<int>nll=nextLargestLeft(nums,n);
        vector<int>nlr=nextLargestRight(nums,n);


        long long mintotal=0;
        long long maxtotal=0;

        for(int i=0;i<n;i++){
            long long left=i-nsl[i];
            long long right=nsr[i]-i;
            long long totalways=(left*right);
            mintotal+=(totalways*nums[i]);

        }
        for(int i=0;i<n;i++){
            long long left=i-nll[i];
            long long right=nlr[i]-i;
            long long totalways=(left*right);
            maxtotal+=(totalways*nums[i]);
            
        }
        return maxtotal-mintotal;
    }
};