class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> maxtime(n+1, INT_MAX);
        vector<pair<int, int>> adj[n+1];

        for (auto time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        maxtime[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // {time, node}

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > maxtime[node]) continue;  // this is the valid check
            for (auto [v, t] : adj[node]) {
                if (maxtime[v] > maxtime[node]+t) {
                    maxtime[v] = maxtime[node]+t;
                    pq.push({maxtime[v], v}); 
                }
            }
        }

        int maxi = *max_element(maxtime.begin()+1, maxtime.end());
        return (maxi == INT_MAX) ? -1 : maxi;
    }
};
