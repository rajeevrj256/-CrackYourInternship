class Solution {
public:
    int t[1001][1001];
    
    bool ispalindrome(string s, int i, int j) {
        if (i >= j) return true;  // Single character or empty substring is a palindrome
        
        if (t[i][j] != -1) return t[i][j];
        
        if (s[i] == s[j]) {
            return t[i][j] = ispalindrome(s, i + 1, j - 1);
        }
        
        return t[i][j] = false;  // If characters don't match, it's not a palindrome
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        memset(t, -1, sizeof(t));  // Initialize memoization table
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {  // Generate all substrings s[i..j]
                if (ispalindrome(s, i, j)) cnt++;
            }
        }
        
        return cnt;
    }
};
