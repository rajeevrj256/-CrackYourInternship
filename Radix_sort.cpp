int maxi(int arr[],int n){
    int maxi=INT_MIN;
    
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
void countsort(int arr[],int n,int exp){
    //int m=maxi(arr);
    
    int count[10]={0};
    int ans[n];
    
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
    
    
}

void radixSort(int arr[], int n) 
{ 
   // code here
   int M=maxi(arr,n);
   
   for(int i=1;M/i>0;i=i*10){
       countsort(arr,n,i);
   }
}