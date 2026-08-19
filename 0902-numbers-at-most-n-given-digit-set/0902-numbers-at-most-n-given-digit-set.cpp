class Solution {
public:

    int dp[10][2][2];
    map<int, bool> mp;
    string s;

    int solve(int idx, bool tight, bool lz) {

        if (idx == s.size())
            return lz ? 0 : 1;

        if (dp[idx][tight][lz] != -1)
            return dp[idx][tight][lz];

        int limit = tight ? s[idx] - '0' : 9;

        int ans = 0;

        for (int dig = 0; dig <= limit; dig++) {

            // Leading zero
            if (lz && dig == 0) {
                ans += solve(
                    idx + 1,
                    tight && (dig == s[idx] - '0'),
                    true
                );
                continue;
            }

            // Actual digit must be present
            if (!mp[dig])
                continue;

            ans += solve(
                idx + 1,
                tight && (dig == s[idx] - '0'),
                false
            );
        }

        return dp[idx][tight][lz] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        s = to_string(n);

        mp.clear();

        for (string d : digits)
            mp[d[0] - '0'] = true;

        memset(dp, -1, sizeof(dp));

        return solve(0, true, true);
    }
};