class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort children's greed factor
        sort(s.begin(), s.end()); // Sort cookies by size
        
        int child = 0, cookie = 0;
        int n = g.size(), m = s.size();
        
        // Step 2: Use two pointers to find maximum satisfied children
        while (child < n && cookie < m) {
            if (s[cookie] >= g[child]) { 
                // If the cookie is large enough, assign it
                child++;
            }
            // Move to the next cookie in either case
            cookie++;
        }
        
        return child; // Number of children satisfied
    
    }
};