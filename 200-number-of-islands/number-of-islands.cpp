class Solution {
private:
    void dfs(int i , int j,vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0')
        return;
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i< n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1'){
                dfs(i,j,grid);
                c++;
            }
        }}
    
    return c;
}};