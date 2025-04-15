class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int count=0;
        int n=arr.length;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int x1=Math.abs(arr[i]-arr[j]);
                    int x2=Math.abs(arr[j]-arr[k]);
                    int x3=Math.abs(arr[i]-arr[k]);

                    if(x1<=a && x2<=b && x3<=c){
                        count++;
                    }

                }
            }
        }

        return count;
    }
}