class Solution {
private:
    void dfs(int start, vector<int> &vis,vector<vector<int>> adjlist){
        vis[start]=1;
        for(auto m:adjlist[start]){
            if(vis[m]==0){
                dfs(m,vis,adjlist);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); //n+1 size
        // vector<int> adjlist[n];
        vector<vector<int>> adjlist(n);
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<n; j++){
                if(isConnected[i][j]==1 && i!=j)//no self loops
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int> vis(n);
        int c = 0;
        for(int i = 0; i<n; i++){
            if(vis[i]==0){
                c++;
                dfs(i, vis, adjlist);
            }
        }
        return c;
    }
};