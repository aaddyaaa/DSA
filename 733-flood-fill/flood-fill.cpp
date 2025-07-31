class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();

        // Base conditions
        if (r < 0 || r >= m || c < 0 || c >= n) return;  // Out of bounds
        if (image[r][c] != originalColor) return;        // Different color
        if (image[r][c] == color) return;                // Already filled

        // Fill the current pixel
        image[r][c] = color;

        // Recursive DFS in 4 directions
        dfs(image, r - 1, c, color, originalColor); // Up
        dfs(image, r + 1, c, color, originalColor); // Down
        dfs(image, r, c - 1, color, originalColor); // Left
        dfs(image, r, c + 1, color, originalColor); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};
