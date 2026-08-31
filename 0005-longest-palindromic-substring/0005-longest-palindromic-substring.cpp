class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(int l, int r, string &s) {
        if (l >= r)
            return true;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] != s[r])
            return dp[l][r] = false;

        return dp[l][r] = solve(l + 1, r - 1, s);
    }

    string longestPalindrome(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));

        int start = 0;
        int maxLen = 1;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (solve(l, r, s)) {
                    int len = r - l + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        start = l;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};