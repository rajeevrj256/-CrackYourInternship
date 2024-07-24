class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            if (set.find(arr[i] + x) != set.end() ||
                set.find(arr[i] - x) != set.end()) {
                return 1;
            }
            set.insert(arr[i]);
        }
        return -1;
    }
};
