class Solution {
public:
    int n, minProfit;
    int dp[101][101][101];
    const int MOD = 1e9 + 7;

    int solve(int i, int members, int profit,
              vector<int>& group, vector<int>& profitArr) {

        if (i == group.size()) {
            if (profit >= minProfit)
                return 1;

            return 0;
        }

        if (dp[i][members][profit] != -1)
            return dp[i][members][profit];

        int skip = solve(
            i + 1,
            members,
            profit,
            group,
            profitArr
        );

        int take = 0;

        if (members + group[i] <= n) {
            int newProfit = min(minProfit, profit + profitArr[i]);

            take = solve(
                i + 1,
                members + group[i],
                newProfit,
                group,
                profitArr
            );
        }

        return dp[i][members][profit] = (skip + take) % MOD;
    }

    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        this->n = n;
        this->minProfit = minProfit;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, group, profit);
    }
};