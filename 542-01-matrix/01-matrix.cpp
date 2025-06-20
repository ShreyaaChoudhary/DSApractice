class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n; j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            for(int k = 0 ; k<4; k++){
                int ni = i+dr[k];
                int nj = j+dc[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n && dist[ni][nj]>(dist[i][j]+1)){
                    dist[ni][nj] = dist[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
        return dist;
    }
};