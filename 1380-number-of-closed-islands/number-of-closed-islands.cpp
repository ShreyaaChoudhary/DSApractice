#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 1)
            return;

        grid[i][j] = 1; // mark visited as water

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Step 1: Remove boundary-connected lands
        for (int i = 0; i < rows; ++i) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][cols - 1] == 0) dfs(grid, i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            if (grid[0][j] == 0) dfs(grid, 0, j);
            if (grid[rows - 1][j] == 0) dfs(grid, rows - 1, j);
        }

        // Step 2: Count closed islands
        int count = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
