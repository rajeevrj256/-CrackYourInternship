class Solution {
  public:
    // Function to find minimum number of pages.
    bool isPossible(int n,int arr[],int page,int m){
        long long student=1;
        long long pagecount=0;
        for(int i=0;i<n;i++){
        if(arr[i]>page)return false;
            if(pagecount+arr[i]<=page){
                pagecount+=arr[i];
            }else{
                student++;
                if(student>m)return false;
               
                pagecount=arr[i];
            }
        }
        return true;;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if(n<m)return -1;
        long long s=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long  e=sum;
        long long mini=INT_MAX;
        while(s<=e){
            long long  mid=(s+e)/2;
            
            if(isPossible(n,arr,mid,m)){
                e=mid-1;
                mini=min(mini,mid);
                
            }else{
                s=mid+1;
            }
        }
        return mini;
        
        
    }
    
};
