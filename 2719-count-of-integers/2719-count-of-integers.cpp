class Solution {
public:

    int mini, maxi;
    int MOD = 1e9 + 7;

    int dp[23][2][401];

    int f(string &s, int idx, bool tight, int sum) {

        if (sum > maxi)
            return 0;

        if (idx == s.size())
            return (sum >= mini && sum <= maxi);

        if (dp[idx][tight][sum] != -1)
            return dp[idx][tight][sum];

        int ub = tight ? s[idx] - '0' : 9;

        int res = 0;

        for (int dig = 0; dig <= ub; dig++) {

            res += f(
                s,
                idx + 1,
                tight && (dig == ub),
                sum + dig
            );

            res %= MOD;
        }

        return dp[idx][tight][sum] = res;
    }

    string subtractOne(string s) {

        int i = s.size() - 1;

        while (s[i] == '0') {
            s[i] = '9';
            i--;
        }

        s[i]--;

        int pos = 0;

        while (pos < s.size() - 1 && s[pos] == '0')
            pos++;

        return s.substr(pos);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {

        mini = min_sum;
        maxi = max_sum;

        // Count [0 ... num2]
        memset(dp, -1, sizeof(dp));

        int right = f(num2, 0, true, 0);

        // Count [0 ... num1-1]
        string prev = subtractOne(num1);

        memset(dp, -1, sizeof(dp));

        int left = f(prev, 0, true, 0);

        return (right - left + MOD) % MOD;
    }
};