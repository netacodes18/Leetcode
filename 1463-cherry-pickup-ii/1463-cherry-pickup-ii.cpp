class Solution {
public:
    int n, m;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int solve(int r, int c1, int c2) {

        // Out of bounds
        if (r >= n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return -1e9;

        // Last row
        if (r == n - 1) {
            if (c1 == c2)
                return grid[r][c1];

            return grid[r][c1] + grid[r][c2];
        }

        // Already calculated
        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int cherries = grid[r][c1];

        // Same cell -> count only once
        if (c1 != c2)
            cherries += grid[r][c2];

        int best = -1e9;

        // Robot 1 and Robot 2 can each move:
        // left, same column, right

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                best = max(best,
                    solve(r + 1, c1 + d1, c2 + d2)
                );
            }
        }

        return dp[r][c1][c2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& g) {

        grid = g;

        n = grid.size();
        m = grid[0].size();

        dp.assign(
            n,
            vector<vector<int>>(
                m,
                vector<int>(m, -1)
            )
        );

        return solve(0, 0, m - 1);
    }
};