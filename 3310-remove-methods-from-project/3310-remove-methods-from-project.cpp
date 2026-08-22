class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& sus, vector<int>& vis) {
        vis[node] = 1;
        sus.push_back(node);

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, sus, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);

        for (vector<int> x : invocations) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
        }

        // Step 2: Find all suspicious methods
        vector<int> sus;
        vector<int> vis(n, 0);

        dfs(k, adj, sus, vis);

        // Step 3: Check if any non-suspicious method calls
        // a suspicious method
        for (vector<int> x : invocations) {
            int u = x[0];
            int v = x[1];

            if (!vis[u] && vis[v]) {
                // Cannot remove suspicious methods
                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        // Step 4: Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};