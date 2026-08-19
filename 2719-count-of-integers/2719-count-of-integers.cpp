class Solution {
public:

    int mini, maxi;
    int MOD = 1e9 + 7;

    int dp[23][2][401];

    int f(string &s, int idx, bool tight, int sum) {

        // Sum already exceeded maximum
        if (sum > maxi)
            return 0;

        // All digits processed
        if (idx == s.size()) {
            return (sum >= mini && sum <= maxi);
        }

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

    int count(string s) {

        memset(dp, -1, sizeof(dp));

        return f(s, 0, true, 0);
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

        int right = count(num2);

        string prev = subtractOne(num1);

        int left = count(prev);

        return (right - left + MOD) % MOD;
    }
};