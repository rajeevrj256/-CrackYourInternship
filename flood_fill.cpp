class Solution {
public:
    void dfs(vector<vector<int>>& image, int s, int c, int color, int originalColor) {
        int n = image.size();
        int m = image[0].size();
        if (s < 0 || c < 0 || s >= n || c >= m || image[s][c] != originalColor) {
            return;
        }
        image[s][c] = color;
        dfs(image, s - 1, c, color, originalColor);
        dfs(image, s + 1, c, color, originalColor);
        dfs(image, s, c - 1, color, originalColor);
        dfs(image, s, c + 1, color, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};
