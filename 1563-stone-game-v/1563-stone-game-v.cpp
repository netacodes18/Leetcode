class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int sum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int l, int r) {
        // Only one stone -> game ends
        if (l == r)
            return 0;

        // Already calculated
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // Try every possible split
        for (int k = l; k < r; k++) {

            int leftSum = sum(l, k);
            int rightSum = sum(k + 1, r);

            if (leftSum < rightSum) {
                // Bob removes right
                // Alice gets leftSum
                ans = max(ans, 
                          leftSum + solve(l, k));
            }
            
            else if (leftSum > rightSum) {
                // Bob removes left
                // Alice gets rightSum
                ans = max(ans, 
                          rightSum + solve(k + 1, r));
            }
            
            else {
                // Equal -> Alice can choose either side
                ans = max(ans,
                          leftSum + max(
                              solve(l, k),
                              solve(k + 1, r)
                          ));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.assign(n, vector<int>(n, -1));

        // Prefix sum
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1);
    }
};