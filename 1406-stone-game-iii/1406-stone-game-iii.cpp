class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // dp[i] = maximum score difference
        // current player can get starting from i
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            int sum = 0;
            dp[i] = INT_MIN;

            for (int take = 1; take <= 3 && i + take <= n; take++) {

                sum += stoneValue[i + take - 1];

                dp[i] = max(dp[i], sum - dp[i + take]);
            }
        }

        if (dp[0] > 0)
            return "Alice";

        if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};