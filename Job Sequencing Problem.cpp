/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(pair<int,int> a , pair<int, int> b){
            
            return a.first > b.first;
        }
    vector<int> JobScheduling(Job arrstruct[], int n) 
    { 
        vector<pair<int,int>> arr;
        
        for(int i = 0 ; i < n ;i++){
            pair<int,int> p = make_pair(arrstruct[i].profit , arrstruct[i].dead);
            arr.push_back(p);
        }
        
        sort(arr.begin() , arr.end() , cmp);
        
        vector<bool> occp(n+1 , true);
        occp[0] = false;
        int sum = 0 , count = 0 ; 
        int limit = 0;
        for(int i = 0 ; i < n ; i++){
            bool block = true;
            for(int j = arr[i].second ; j > 0  && block; j--){
                
                if(j < limit){
                    block = false;
                }
                else if(occp[j]){
                    occp[j] = false;
                    count++;
                    sum += arr[i].first;
                   block = false;
                }
                if(j == 1 && block == true){
                    limit = max(arr[i].second ,limit);
                }
            }
            
        }
        
        return {count , sum };
        
    } 
};