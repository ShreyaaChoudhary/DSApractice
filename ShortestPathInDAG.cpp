// User function Template for C++
class Solution {
  private:
    void toposort(int node, vector<int> &vis, stack<int> &st, vector<pair<int,int>> adj[]){
        vis[node] = 1;
        for(auto ad:adj[node]){
            int v = ad.first;
            if(!vis[v]){
                toposort(v,vis,st,adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(auto edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v,w});
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0 ; i< V ; i++){
            if(!vis[i]){
                toposort(i,vis,st,adj);
            }
        }
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(dist[node]!=INT_MAX){
                for(auto it:adj[node]){
                    int v = it.first;
                    int w = it.second;
                    if(dist[node]+w<dist[v]){
                        dist[v]=dist[node]+w;
                    }
                }
            }
        }
        for(int i = 0 ; i<V ; i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
