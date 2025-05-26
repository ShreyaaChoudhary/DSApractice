class Solution {
private:
    void dfs_traversal(int node, vector<vector<int>> &adjList, vector<int> &vis){
        vis[node] = 1;
        for(int it: adjList[node]){
            if(!vis[it]){
                dfs_traversal(it, adjList, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Convert adj matrix to adj list (we are tring to solve the problems in adj list)
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //check for connections and self loops
                if (isConnected[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i); 
                }   
            }
        }
        //Variables
        vector<int> vis(n,0);
        int count = 0;

        //Updating the count variable and calling the function
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                count++;
                dfs_traversal(i, adjList, vis);
            }
        }
        return count;
    }
};