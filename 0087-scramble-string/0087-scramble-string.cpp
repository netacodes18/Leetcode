class Solution {
public:
    int dp[31][31][31];

    bool solve(int i1, int i2, int len, string& s1, string& s2) {

        if (dp[i1][i2][len] != -1)
            return dp[i1][i2][len];

        // If both substrings are exactly same
        if (s1.substr(i1, len) == s2.substr(i2, len))
            return dp[i1][i2][len] = true;

        // Try every possible split
        for (int k = 1; k < len; k++) {

            bool noSwap =
                solve(i1, i2, k, s1, s2) &&
                solve(i1 + k, i2 + k, len - k, s1, s2);

            bool swap =
                solve(i1, i2 + len - k, k, s1, s2) &&
                solve(i1 + k, i2, len - k, s1, s2);

            if (noSwap || swap)
                return dp[i1][i2][len] = true;
        }

        return dp[i1][i2][len] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length())
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s1.length(), s1, s2);
    }
};