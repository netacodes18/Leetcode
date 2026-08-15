class Solution {
public:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a)
            return a;

        return parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);

        if (a == b) return;

        if (rank[a] < rank[b])
            parent[a] = b;

        else if (rank[a] > rank[b])
            parent[b] = a;

        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> parent(n);
        vector<int> rank(n, 0);

        // Initialize DSU
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect stones with same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    unite(i, j, parent, rank);
                }
            }
        }

        // Count components
        int component = 0;

        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i)
                component++;
        }

        return n - component;
    }
};