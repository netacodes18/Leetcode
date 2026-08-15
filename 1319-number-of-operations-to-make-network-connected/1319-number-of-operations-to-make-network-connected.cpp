class Solution {
public:

    int find(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            unionSet(u, v, parent, rank);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i)
                components++;
        }

        return components - 1;
    }
};