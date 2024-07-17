class RandomizedCollection {
public:
   unordered_map <int,int>m;
   vector<int>nums;
   int count=0;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool present=m[val]>0;
        m[val]++;
        nums.push_back(val);
        count++;
        return !present;
        
    }
    
    bool remove(int val) {
        if (m[val] == 0) return false;
        m[val]--;
        if(m[val]==0) m.erase(val);
        auto it=find(nums.begin(),nums.end(),val);
        if(it!=nums.end()){
            nums.erase(it);
        }
        count--;
        return true ;
        
    }
    
    int getRandom() {
        if(nums.empty())return 0;
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */