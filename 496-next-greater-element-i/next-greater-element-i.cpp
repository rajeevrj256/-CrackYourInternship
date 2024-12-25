class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        map<int,int>hash;

        for(int num:nums2){
            while(!s.empty() && s.top()<num){
                hash[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        vector<int>ans;

        while(!s.empty()){
            hash[s.top()]=-1;
            s.pop();
        }


        for(int num:nums1){
               ans.push_back(hash[num]);
        }

        return ans;
    }
};