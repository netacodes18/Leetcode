class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();

        // Prefix sums
        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // If current player takes all stones
        int dp = prefix[n - 1];

        // Try smaller prefixes backwards
        for (int i = n - 2; i >= 1; i--) {

            // Take prefix[i]
            // Then opponent gets dp advantage
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};