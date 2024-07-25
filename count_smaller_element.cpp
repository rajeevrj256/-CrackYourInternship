class Solution {
  public:
    int binaryserach(vector<int>&arr,int target,int start,int end){
       
        int count=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]<target){
                count+=mid-start+1;
                start=mid+1;
            }else{
                
                end=mid-1;
            }
        }
        return count;
        
    };
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        vector<int> a;
        a.push_back(arr[n-1]);
    
        int i = n-2;
        while(i >= 0){
            int index  = binaryserach(a,arr[i],0,a.size()-1);
            ans[i] = index;
            a.insert(a.begin() + index, arr[i]);
            i--;
        }
        
        return ans;
        
        
    }
};