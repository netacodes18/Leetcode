class Solution {
public:

    int dp[20][2][20];

    int solve(string &s, int idx, bool tight, int cnt_of_1) {

        if (idx == s.size())
            return cnt_of_1;

        if (dp[idx][tight][cnt_of_1] != -1)
            return dp[idx][tight][cnt_of_1];

        int lb = 0;
        int ub = tight ? s[idx] - '0' : 9;

        int res = 0;

        for (int dig = lb; dig <= ub; dig++) {

            res += solve(
                s,
                idx + 1,
                tight && (dig == ub),
                cnt_of_1 + (dig == 1)
            );
        }

        return dp[idx][tight][cnt_of_1] = res;
    }

    int countDigitOne(int n) {

        string s = to_string(n);

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, true, 0);
    }
};