class Solution {
private:
    bool dfs(int node, vector<bool> &vis, vector<bool> &pathvis, stack<int> &st, vector<vector<int>> &prerequisites){
        vis[node] = true;
        pathvis[node] = true;
        for(auto adj:prerequisites[node]){
            if(!vis[adj])
            {if(dfs(adj, vis, pathvis, st, prerequisites)==true)
                return true;
            }
            if(pathvis[adj]) return true;
        }
        pathvis[node] = false;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(n);
        for(auto p:prerequisites){
            int b = p[1];
            int a = p[0];
            adjlist[b].push_back(a);
        }
        vector<bool> vis(n,false);
        vector<bool> pathvis(n, false);
        stack<int> st;
        vector<int> ans;

        for(int i =0 ; i<n ;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathvis, st, adjlist)==true)
                return ans;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};