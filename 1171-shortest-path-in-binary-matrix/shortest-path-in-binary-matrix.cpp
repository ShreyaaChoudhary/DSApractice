class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        vector<pair<int,int>> dir = {{0,1},{1,0},{1,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(x==n-1 && y==n-1) return grid[x][y];
            for(auto [dx,dy] :dir){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    grid[nx][ny] = 1+grid[x][y];
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};