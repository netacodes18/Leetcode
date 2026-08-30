class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0;

        // Convert matrix to bitmask
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j])
                    start |= (1 << (i * n + j));
            }
        }

        queue<int> q;
        unordered_set<int> vis;

        q.push(start);
        vis.insert(start);

        int steps = 0;
        int dr[] = {0, 0, 0, 1, -1};
        int dc[] = {0, 1, -1, 0, 0};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int state = q.front();
                q.pop();

                if (state == 0)
                    return steps;

                // Try flipping every cell
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int next = state;

                        // Flip itself + 4 neighbours
                        for (int k = 0; k < 5; k++) {
                            int ni = i + dr[k];
                            int nj = j + dc[k];

                            if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                                next ^= (1 << (ni * n + nj));
                        }

                        if (!vis.count(next)) {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};