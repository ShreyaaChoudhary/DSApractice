class Solution {
public:
    // Helper function for the recursive DFS
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Base Case 1: Out of bounds
        if (r < 0 || r >= n || c < 0 || c >= m) {
            return;
        }

        // Base Case 2: Pixel is not the original color OR it's already the new color
        // This is crucial to stop recursion and prevent infinite loops
        if (image[r][c] != originalColor) {
            return;
        }

        // Base Case 3: Optimization - If the original color is the same as the new color, do nothing.
        // This avoids infinite recursion when color == image[sr][sc] initially.
        if (originalColor == newColor) {
             return;
        }


        // Change the color of the current pixel
        image[r][c] = newColor;

        // Recursively call for 4-directionally adjacent pixels
        dfs(image, r + 1, c, originalColor, newColor); // Down
        dfs(image, r - 1, c, originalColor, newColor); // Up
        dfs(image, r, c + 1, originalColor, newColor); // Right
        dfs(image, r, c - 1, originalColor, newColor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Store the original color of the starting pixel
        int originalColor = image[sr][sc];

        // Call the DFS helper function
        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};