#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int t[20001];

    int solve(vector<int>& arr, int i) {
        if (i >= arr.size()) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int del = arr[i];
        int sum = arr[i];
        int idx = i + 1;

        // Accumulate the sum of all elements equal to `del`
        while (idx < arr.size() && arr[idx] == del) {
            sum += arr[idx];
            idx++;
        }

        // Skip over elements that are equal to `del + 1`
        while (idx < arr.size() && arr[idx] == del + 1) {
            idx++;
        }

        // Compute the maximum of taking or skipping the current number
        return t[i] = max(sum + solve(arr, idx), solve(arr, i + 1));
    }

    int deleteAndEarn(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        sort(nums.begin(), nums.end());
        return solve(nums, 0);
    }
};
