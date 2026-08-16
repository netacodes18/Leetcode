class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent,
             vector<int> adj[],
             vector<int>& vis,
             vector<int>& tin,
             vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {

            // Don't go back through the edge
            // from which we came
            if (it == parent)
                continue;

            if (vis[it] == 0) {

                // DFS
                dfs(it, node, adj, vis, tin, low, bridges);

                // Update low value after returning
                low[node] = min(low[node], low[it]);

                // No alternate path from it's subtree
                // back to node or any ancestor
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {

                // Back edge
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        // Build adjacency list
        vector<int> adj[n];

        for (auto edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridges;

        dfs(0, -1, adj, vis, tin, low, bridges);

        return bridges;
    }
};