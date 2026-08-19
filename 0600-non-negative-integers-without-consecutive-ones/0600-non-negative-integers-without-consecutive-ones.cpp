class Solution {
public:

    int dp[35][2][2];

    int f(string &s, int idx, bool tight, bool prev) {

        if (idx == s.size())
            return 1;

        if (dp[idx][tight][prev] != -1)
            return dp[idx][tight][prev];

        int ub = tight ? s[idx] - '0' : 1;

        int ans = 0;

        for (int dig = 0; dig <= ub; dig++) {

            if (dig == 1 && prev)
                continue;

            ans += f(
                s,
                idx + 1,
                tight && (dig == ub),
                dig == 1
            );
        }

        return dp[idx][tight][prev] = ans;
    }

    int findIntegers(int n) {

        string s = bitset<32>(n).to_string();

        int idx = s.find('1');
        s = s.substr(idx);

        memset(dp, -1, sizeof(dp));

        return f(s, 0, 1, 0);
    }
};