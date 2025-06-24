class Solution {
private:
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string& word, vector<vector<bool>>& vis) {
        int m = board.size();
        int n = board[0].size();
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || board[i][j] != word[idx])
            return false;
        vis[i][j] = true;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (dfs(ni, nj, idx + 1, board, word, vis))
                return true;
        }
        vis[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word, vis))
                        return true;
                }
            }
        }

        return false;
    }
};
