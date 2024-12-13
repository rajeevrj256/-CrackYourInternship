class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
       
        priority_queue<pair<int,int>, vector<pair<int, int>>,
        greater<pair<int,int >>> q;
        int i=0;
        for(int num:nums){
           q.push({num,i++});
        }

        
        long long  score=0;
        vector<bool>marked(n,false);
        while(!q.empty()){
            pair<int,int>front=q.top();
            int num=front.first;
            int idx=front.second;
            q.pop();
            
            
                if(!marked[idx]){
                    marked[idx]=true;
                    score+=num;
                    if(idx>0){
                        marked[idx-1]=true;

                    }

                    if(idx<n-1){
                        marked[idx+1]=true;
                    }
                }
          
        }
        return score;


    }
};