class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>hash;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
        greater<pair<int, vector<int>>>> q;
        int i=0;
        for(int num:nums){
            hash[num].push_back(i++);
        }

        for(auto i:hash){
            q.push({i.first,i.second});
        }
        long long  score=0;
        vector<bool>marked(n,false);
        while(!q.empty()){
            pair<int,vector<int>>front=q.top();
            q.pop();
            vector<int>arr=front.second;
            for(int num:arr){
                if(!marked[num]){
                    marked[num]=true;
                    score+=front.first;
                    if(num>=1 && num<n-1){
                        marked[num-1]=true;
                        marked[num+1]=true;

                    }

                    if(num==0){
                          marked[num+1]=true;
                    }else if(num==n-1){
                        marked[num-1]=true;
                    }
                }
            }
        }
        return score;


    }
};