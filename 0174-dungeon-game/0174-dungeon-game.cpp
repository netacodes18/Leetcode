class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& dungeon, int i, int j) {

        // Princess cell
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = INT_MAX;
        int right = INT_MAX;

        if (i + 1 < m) {
            down = dfs(dungeon, i + 1, j);
        }

        if (j + 1 < n) {
            right = dfs(dungeon, i, j + 1);
        }

        // Choose the path requiring less health
        int need = min(down, right);

        dp[i][j] = max(1, need - dungeon[i][j]);

        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        m = dungeon.size();
        n = dungeon[0].size();

        dp.assign(m, vector<int>(n, -1));

        return dfs(dungeon, 0, 0);
    }
};