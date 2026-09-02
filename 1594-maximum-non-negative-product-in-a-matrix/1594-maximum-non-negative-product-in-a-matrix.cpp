class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxi(n, vector<long long>(m));
        vector<vector<long long>> mini(n, vector<long long>(m));

        maxi[0][0] = mini[0][0] = grid[0][0];

        // First row
        for (int j = 1; j < m; j++) {
            maxi[0][j] = mini[0][j] =
                maxi[0][j - 1] * grid[0][j];
        }

        // First column
        for (int i = 1; i < n; i++) {
            maxi[i][0] = mini[i][0] =
                maxi[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                long long a = maxi[i - 1][j] * grid[i][j];
                long long b = mini[i - 1][j] * grid[i][j];
                long long c = maxi[i][j - 1] * grid[i][j];
                long long d = mini[i][j - 1] * grid[i][j];

                maxi[i][j] = max({a, b, c, d});
                mini[i][j] = min({a, b, c, d});
            }
        }

        if (maxi[n - 1][m - 1] < 0)
            return -1;

        return maxi[n - 1][m - 1] % MOD;
    }
};