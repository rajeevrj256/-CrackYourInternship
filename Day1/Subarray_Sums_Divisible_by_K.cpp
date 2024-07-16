class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp={{0,1}};
        int prefixsum=0;
        int count=0;
        for(int num:nums){
            prefixsum+=num;
            int remainder=((prefixsum % k) + k) % k;
            if(mp.find(remainder)!=mp.end()){
                count+=mp[remainder];
            }
            mp[remainder]++;
        }
        return count;
    }
};