class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>>arr;
	    
	    for(int i=0;i<n;i++){
	        arr.push_back({nums[i],i});
	    }
	    sort(arr.begin(),arr.end());
	    int ans=0;
	    for(int i=0;i<n;i++){
	        if(arr[i].second==i)continue;
	        else{
	            swap(arr[i],arr[arr[i].second]);
	            ans++;
	            i--;
	        }
	    }
	    return ans;
	}
};
