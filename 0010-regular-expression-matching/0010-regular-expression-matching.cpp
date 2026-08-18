class Solution {
public:

    vector<vector<int>> dp;

    bool solve(int i, int j, string s, string p) {

        // Pattern khatam
        if (j == p.length()) {
            return i == s.length();
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Current character match karta hai?
        bool first_char = false;

        if (i < s.length() &&
            (p[j] == '.' || p[j] == s[i])) {
            first_char = true;
        }

        // Next character '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {

            // * ko 0 times use karo
            bool not_take = solve(i, j + 2, s, p);

            // * ko 1+ times use karo
            bool take = first_char && solve(i + 1, j, s, p);

            return dp[i][j] = take || not_take;
        }

        // Normal character / '.'
        return dp[i][j] = first_char &&
                          solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {

        dp.assign(s.length() + 1,
                  vector<int>(p.length() + 1, -1));

        return solve(0, 0, s, p);
    }
};