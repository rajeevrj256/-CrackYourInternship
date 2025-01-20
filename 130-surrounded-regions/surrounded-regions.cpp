class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int row, int col, int m, int n) {
        vis[row][col] = true;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];

            if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y] && board[x][y] == 'O') {
                dfs(board, vis, x, y, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return; // Edge case: empty board
        int n = board[0].size();

        // Initialize the visited matrix
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Traverse the boundary rows and columns
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(board, vis, 0, j, m, n);
            }
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) {
                dfs(board, vis, m - 1, j, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(board, vis, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                dfs(board, vis, i, n - 1, m, n);
            }
        }

        // Convert 'O' to 'X' for all unvisited 'O's and restore boundary-connected 'O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
