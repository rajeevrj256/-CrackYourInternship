class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, bool> seen;
        int insert = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!seen[nums[i]]) {
                nums[insert] = nums[i];
                insert++;
                seen[nums[i]] = true;
            }
        }
        return insert;
    }
};