class Solution {
public:
    long long mod = 1e9 + 7;
    
    // Function to get next smaller left index
    vector<int> getnsl(vector<int>& arr, int n) {
        vector<int> res;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            // Find the index of the first element smaller than arr[i]
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If the stack is empty, there is no smaller element on the left, set to -1
            res.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        return res;
    }
    
    // Function to get next smaller right index
    vector<int> getnsr(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            // Find the index of the first element smaller than arr[i] from the right
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // If the stack is empty, there is no smaller element on the right, set to n (out of bounds)
            res[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return res;
    }
    
    // Function to calculate the sum of subarray minimums
    long long  sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnsl(arr, n);
        vector<int> nsr = getnsr(arr, n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long nslno = i - nsl[i];
            long long nsrno = nsr[i] - i;
            long long ways = nslno * nsrno;
            long long totalsum = (arr[i] * ways) ;
            ans = (ans + totalsum) ;
        }

        return ans;
    }

    // Function to get next larger left index
    vector<int> getnll(vector<int>& arr, int n) {
        vector<int> res;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            res.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        return res;
    }
    
    // Function to get next larger right index
    vector<int> getnlr(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            res[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return res;
    }
    
    // Function to calculate the sum of subarray maximums
    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnll(arr, n);
        vector<int> nsr = getnlr(arr, n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long nslno = i - nsl[i];
            long long nsrno = nsr[i] - i;
            long long ways = nslno * nsrno;
            long long totalsum = (arr[i] * ways);
            ans = (ans + totalsum) ;
        }

        return ans;
    }

    // Final function to calculate subarray ranges
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMax(nums);
        long long minSum = sumSubarrayMins(nums);

        // The result should be the difference of the maximum sum and the minimum sum
        return (maxSum - minSum ) ;
    }
};
