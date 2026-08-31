class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int j, string &s) {
        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = 2 + solve(i + 1, j - 1, s);
        }

        return dp[i][j] = max(
            solve(i + 1, j, s),
            solve(i, j - 1, s)
        );
    }

    int minInsertions(string s) {
        n = s.length();

        dp.assign(n, vector<int>(n, -1));

        int lps = solve(0, n - 1, s);

        return n - lps;
    }
};