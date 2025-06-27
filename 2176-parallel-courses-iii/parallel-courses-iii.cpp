class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, st);
            }
        }
        st.push(node); 
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1); 
        for (auto& rel : relations) {
            int u = rel[0], v = rel[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n + 1, false);
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<int> finishTime(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            finishTime[i] = time[i - 1]; 
        }

        while (!st.empty()) {
            int course = st.top();
            st.pop();
            for (int next : adj[course]) {
                finishTime[next] = max(finishTime[next], finishTime[course] + time[next - 1]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, finishTime[i]);
        }
        return ans;
    }
};
