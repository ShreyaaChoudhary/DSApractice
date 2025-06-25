class Solution {
private:
    void dfs(int i , int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[i][j]=1;
         int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k = 0 ; k<4 ; k++){
            int ni = dr[k]+i;
            int nj = j+dc[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && grid[ni][nj]==1)
            dfs(ni,nj,vis,grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i =0 ; i< n ; i++){
            if(grid[0][i]==1 && !vis[0][i])
            dfs(0,i,vis,grid);
            if(grid[m-1][i]==1 && !vis[m-1][i])
            dfs(m-1,i,vis,grid);
        }
        for(int i = 0 ; i< m ; i++){
            if(grid[i][0]==1 && !vis[i][0])
            dfs(i,0,vis,grid);
            if(grid[i][n-1]==1 && !vis[i][n-1])
            dfs(i,n-1,vis,grid);
        }
        int c = 0;
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid[i][j]==1 && !vis[i][j])
                c++;
            }
        }
        return c;
    }
};