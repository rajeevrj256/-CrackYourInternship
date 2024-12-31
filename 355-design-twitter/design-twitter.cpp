class Twitter {
public:
    int postseq=1;
    unordered_map<int,vector<pair<int,int>>>postweet;
    unordered_map<int,unordered_set<int>>follower;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        postweet[userId].push_back({postseq++,tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>q;

        for(auto& post:postweet[userId]){

             q.push(post);
        }
        for(int followeeId:follower[userId]){
            for (auto& post : postweet[followeeId]) {
                q.push(post);
            }
        }

        vector<int>ans;
        while(!q.empty() && ans.size()<10){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */