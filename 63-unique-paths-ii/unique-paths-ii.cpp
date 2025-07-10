class Solution {
public:
    int f(int i , int j , vector<vector<int>> &dp, vector<vector<int>>& Grid) {
        if (i < 0 || j < 0) return 0;
        if (Grid[i][j] == 1) return 0;     // obstacle cell
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, dp, Grid);
        int left = f(i, j - 1, dp, Grid);
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size();
        int n = Grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, Grid);
    }
};
