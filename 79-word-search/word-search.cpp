class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int index, int n, int m) {
        if (index >= word.size()) return true;

        // Correct order of boundary check and character match
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[index]) return false;

        char temp = board[x][y];  // Store the original character
        board[x][y] = '#';  // Mark as visited

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (dfs(board, word, nx, ny, index + 1, n, m)) {
                return true;
            }
        }

        board[x][y] = temp;  // Backtrack to restore the original character

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0, n, m)) {
                    return true;
                }
            }
        }

        return false;
    }
};
