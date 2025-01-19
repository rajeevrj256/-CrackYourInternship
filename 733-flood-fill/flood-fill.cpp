class Solution {
public:
    int n, m, cur;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        cur = image[sr][sc];
        if (cur == color) return image; // Avoid redundant work if the color is already the target
        dfs(sr, sc, image, color);
        return image;
    }

    void dfs(int i, int j, vector<vector<int>>& image, int color) {
        if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != cur)
            return;
        image[i][j] = color;
        dfs(i + 1, j, image, color);
        dfs(i - 1, j, image, color);
        dfs(i, j + 1, image, color);
        dfs(i, j - 1, image, color);
    }
};
