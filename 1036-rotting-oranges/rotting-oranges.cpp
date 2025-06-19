class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, tot = 0 , rot = 0;
        queue<vector<int>> q;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< m; j++){
                if(grid[i][j]!=0){tot++;}
                if(grid[i][j]==2){
                    rot++;
                    q.push({i,j,0});
                }
                if(grid[i][j]==1)
                fresh++;
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int time = 0 ;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front[0], c = front[1], t = front[2];
            time = max(time, t);
            for(int i = 0 ; i< 4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                q.push({nr, nc, t+1});
                grid[nr][nc] = 2;
                rot++;
                }
            }
        }
        if(rot==tot)
        return time;
        else
        return -1;
    }
};