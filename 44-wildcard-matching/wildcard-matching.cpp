class Solution {
public:
    bool checkStar(string &p, int i) {
        for (int j = 0; j <= i; j++) {
            if (p[j] != '*') return false;
        }
        return true;
    }

    bool help(string &p, string &s, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;  // Both strings are exhausted
        if (i < 0 && j >= 0) return false; // Pattern exhausted but string remains
        if (j < 0 && i >= 0) return checkStar(p, i); // Check if remaining pattern is all '*'

        if (dp[i][j] != -1) return dp[i][j];

        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = help(p, s, i - 1, j - 1, dp);
        }
        if (p[i] == '*') {
            return dp[i][j] = help(p, s, i - 1, j, dp) || help(p, s, i, j - 1, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return help(p, s, n - 1, m - 1, dp);
    }
};
