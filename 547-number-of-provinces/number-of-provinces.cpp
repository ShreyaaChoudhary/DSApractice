class Solution {
private:
    void dfsofgraph(vector<int> &vis,vector<int> adj[], int node){
        vis[node]=1;
        for(auto m:adj[node]){
            if(!vis[m]){
                dfsofgraph(vis,adj,m);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjlist[n];
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j<n; j++)
            {
                if(isConnected[i][j]==1 && i!=j){
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }}
        }
        vector<int> vis(n);
        int c =0;
        for(int i = 0 ; i< n ; i++){
            if(vis[i]==0){
                c++;
                dfsofgraph(vis, adjlist, i);
            }
        }
        return c;
    }
};