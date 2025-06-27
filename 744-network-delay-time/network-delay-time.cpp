class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> maxtime(n + 1, INT_MAX); // 1-based indexing
        vector<pair<int, int>> adj[n + 1];

        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // {time, node}

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (maxtime[node] != INT_MAX) continue; 
            maxtime[node] = time; 

            for (auto [v, t] : adj[node]) {
                if (maxtime[v] == INT_MAX) {
                    pq.push({time + t, v}); 
                }
            }
        }

        int maxi = *max_element(maxtime.begin() + 1, maxtime.end());
        return (maxi == INT_MAX) ? -1 : maxi;
    }
};
