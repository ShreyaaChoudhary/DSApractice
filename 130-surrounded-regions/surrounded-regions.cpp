class Solution {
private:
    void dfs(vector<vector<int>>& vis, int i, int j,
             vector<vector<char>> &board) {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] &&
                board[nr][nc] == 'O') {
                dfs(vis, nr, nc, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            // boundary rows and unvisited
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(vis, i, 0, board);
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                dfs(vis, i, n - 1, board);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(vis, 0, j, board);
            }
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) {
                dfs(vis, m - 1, j, board);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
        }
    }
};