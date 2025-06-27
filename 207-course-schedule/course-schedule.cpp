class Solution {
private:
    bool dfs(int node, vector<bool> &vis, vector<bool> &pathvis, int n, vector<vector<int>> &adjlist){
        vis[node] = true;
        pathvis[node] = true;
        for(auto adj: adjlist[node]){
            if(!vis[adj]){
                if(dfs(adj, vis, pathvis, n, adjlist)==true)
                    return true;
            }
            if(pathvis[adj])
            return true;
        }
        pathvis[node] = false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(n);
        for(auto m : prerequisites){
            int b = m[1];
            int a = m[0];
            adjlist[b].push_back(a);
        }
        vector<bool> vis(n,false);
        vector<bool> pathvis(n,false);
        stack<int> st;
        for(int i = 0 ; i< n ; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathvis, n, adjlist)==true)
                return false;
            }
        }
        return true;
        
    }
};