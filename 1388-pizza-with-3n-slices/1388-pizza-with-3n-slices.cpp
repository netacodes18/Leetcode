class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& slices, int idx, int cnt, int end) {
        if (cnt == 0) return 0;
        if (idx > end) return -1e9;

        if (dp[idx][cnt] != -1)
            return dp[idx][cnt];

        // Don't choose idx
        int skip = solve(slices, idx + 1, cnt, end);

        // Choose idx
        // idx+1 becomes unavailable, so jump to idx+2
        int take = slices[idx] +
                   solve(slices, idx + 2, cnt - 1, end);

        return dp[idx][cnt] = max(skip, take);
    }

    int maxSizeSlices(vector<int>& slices) {
        n = slices.size();
        int k = n / 3;

        // Case 1: don't choose first
        dp.assign(n + 2, vector<int>(k + 1, -1));
        int a = solve(slices, 1, k, n - 1);

        // Case 2: don't choose last
        dp.assign(n + 2, vector<int>(k + 1, -1));
        int b = solve(slices, 0, k, n - 2);

        return max(a, b);
    }
};