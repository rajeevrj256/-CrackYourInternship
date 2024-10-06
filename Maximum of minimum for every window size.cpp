class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        stack<int>s;
        vector<int>res(n+1,0);
        vector<int>left(n);
        vector<int>right(n);
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            left[i]=s.empty()?-1:s.top();
            
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            right[i]=s.empty()?n:s.top();
            
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            int window=right[i]-left[i]-1;
            res[window]=max(res[window],arr[i]);
        }
        for(int i=n-1;i>=1;i--){
            res[i]=max(res[i],res[i+1]);
        }
        vector<int>ans(res.begin()+1,res.end());
        return ans;
        
    }
};