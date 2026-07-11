class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> maxi;

    int solve(int i, int j) {
        // Base case
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        // Try every possible partition
        for (int k = i; k < j; k++) {
            int left = solve(i, k);
            int right = solve(k + 1, j);

            int cost = left + right + (maxi[i][k] * maxi[k + 1][j]);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        dp.assign(n, vector<int>(n, -1));
        maxi.assign(n, vector<int>(n, 0));

        // Precompute maximum element in every range
        for (int i = 0; i < n; i++) {
            maxi[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[i][j] = max(maxi[i][j - 1], arr[j]);
            }
        }

        return solve(0, n - 1);
    }
};