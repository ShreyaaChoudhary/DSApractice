class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 1: Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 2: Check for negative weight cycle
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                return {-1}; // negative weight cycle detected
            }
        }

        // Step 3: Replace unreachable nodes' distances with 1e8
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = 1e8;
        }

        return dist;
    }
};
