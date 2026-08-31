class Solution {
public:
    int sl, pl;

    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {

        // both string and pattern exhausted
        if (i == sl && j == pl)
            return true;

        // pattern exhausted but string remains
        if (j == pl)
            return false;

        // string exhausted
        // remaining pattern must be all '*'
        if (i == sl) {
            for (int k = j; k < pl; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // dp memo
        if (dp[i][j] != -1)
            return dp[i][j];

        // '*' has two options
        if (p[j] == '*') {

            // don't take '*'
            bool notTake = solve(i, j + 1, s, p, dp);

            // take '*'
            bool take = solve(i + 1, j, s, p, dp);

            return dp[i][j] = take || notTake;
        }

        // normal character or '?'
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        sl = s.length();
        pl = p.length();

        vector<vector<int>> dp(
            sl + 1,
            vector<int>(pl + 1, -1)
        );

        return solve(0, 0, s, p, dp);
    }
};