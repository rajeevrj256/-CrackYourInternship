class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If the starting or ending point is blocked, return -1
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }

        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // Mark the start as visited

        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            // Explore each level
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                // If we reach the bottom-right corner, return steps
                if (row == n - 1 && col == m - 1) {
                    return steps;
                }

                // Explore all 8 directions
                for (int j = 0; j < 8; j++) {
                    int nx = row + dx[j];
                    int ny = col + dy[j];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;  // Mark as visited
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;  // If no path is found
    }
};
