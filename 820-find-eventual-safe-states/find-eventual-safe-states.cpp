class Solution {
private:
    bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>> &graph,vector<int> &safe){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto adj:graph[node]){
            if(!vis[adj]){
                if(dfs(adj,vis,pathvis,graph,safe))
                return true;
            }
            if(pathvis[adj]) return true;
        }
        pathvis[node]=0;
        safe[node] = 1;
        return false;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> vis(m,0), pathvis(m,0), safenodes(m,0);
        for(int i = 0 ; i< m ; i++){
            if(!vis[i])
            dfs(i,vis,pathvis, graph, safenodes);
        }
    
    vector<int> ans;
    for(int i = 0; i<m ; i++){
        if(safenodes[i]){
            ans.push_back(i);
        }
    }
    return ans;
}};