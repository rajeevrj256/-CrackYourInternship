class Solution
{
public:
    int mod = 1e9 + 7;
    int t[5000][10];
    int help(int n, int s, vector<list<int>> &adj)
    {
        if (n == 0)
            return 1;

        if (t[n][s] != -1)
            return t[n][s];
        int ans = 0;
        for (auto &cell : adj[s])
        {
            ans = (ans + help(n - 1, cell, adj)) % mod;
        }
        return t[n][s] = ans;
    }
    int knightDialer(int n)
    {
        int res = 0;
        vector<list<int>> adj = {
            {4, 6}, {6, 8}, {9, 7}, {8, 4}, {3, 9, 0}, {}, {1, 7, 0}, {6, 2}, {1, 3}, {2, 4}};
        
        
        memset(t, -1, sizeof(t));

        for (int i = 0; i <= 9; i++)
        {
            res = (res + help(n - 1, i, adj)) % mod;
        }
        return res;
    }
};