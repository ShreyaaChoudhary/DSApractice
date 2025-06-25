class Solution {
private:
    void dfs(int k , int j , vector<vector<int>> &vis, vector<vector<int>> &grid1, vector<vector<int>> &grid2, bool &flag){
        int m = grid1.size();
        int n = grid1[0].size();
        if(grid1[k][j]==0) flag=false;
        vis[k][j] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {-0,1,0,-1};
        for(int i = 0 ; i<4 ; i++){
            int ni = k+dr[i];
            int nj = j+dc[i];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] &&  grid2[ni][nj]==1){
                dfs(ni,nj,vis,grid1,grid2,flag);
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int c = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    bool flag = true;
                    dfs(i,j,vis, grid1, grid2,flag);
                    if(flag) c++;
                    
                }
            }
        }
        return c;
    }
};