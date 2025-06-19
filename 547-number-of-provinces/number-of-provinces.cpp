class Solution {
private:
    void dfs(vector<int> adjlist[], vector<int> &vis, int start){
        vis[start] = 1; 
        for(auto m:adjlist[start]){
            if(vis[m]==0){
                dfs(adjlist, vis, m);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjlist[n];
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);

                }
            }
        }
        vector<int> vis(n);
        int c = 0 ;
        for(int i = 0 ; i< n ; i++){
            if(vis[i]==0){
                c++;
                dfs(adjlist, vis, i);
            }
        }
        return c;
    }
};