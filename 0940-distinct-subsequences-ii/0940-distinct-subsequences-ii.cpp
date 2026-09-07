class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    int dp[2001];
    vector<int> nextSame;

    int solve(int i, string &s) {
        if (i == n)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long skip = solve(i + 1, s);

        long long take = solve(i + 1, s);

        if (nextSame[i] != -1) {
            take -= solve(nextSame[i] + 1, s);
        }

        return dp[i] = (skip + take) % MOD;
    }

    int distinctSubseqII(string s) {
        n = s.length();

        memset(dp, -1, sizeof(dp));

        nextSame.assign(n, -1);

        vector<int> last(26, -1);

        for (int i = n - 1; i >= 0; i--) {
            int ch = s[i] - 'a';

            nextSame[i] = last[ch];

            last[ch] = i;
        }

        return (solve(0, s) - 1 + MOD) % MOD;
    }
};