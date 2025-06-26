class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                if (dist[neighbor] > dist[node] + 1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
