class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // 1. Find median
        int mid = (n - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];

        // Virtual index mapping
        auto idx = [&](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        // 2. 3-way partition
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[idx(j)] > median) {
                swap(nums[idx(i++)], nums[idx(j++)]);
            } else if (nums[idx(j)] < median) {
                swap(nums[idx(j)], nums[idx(k--)]);
            } else {
                j++;
            }
        }
    }
};
