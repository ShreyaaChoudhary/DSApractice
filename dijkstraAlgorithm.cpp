// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,src}); // distance , node
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            for(auto ad:adj[node]){
                int v = ad.first;
                int w = ad.second;
                if(dist[node]+w<dist[v]){
                    dist[v] = w+dist[node];
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i = 0 ; i<V ; i++){
            if(dist[i]==INT_MAX){
                dist[i]= -1;
            }
        }
        return dist;
    }
};
