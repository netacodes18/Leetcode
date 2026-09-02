class Solution {
public:
    vector<int> arr1, arr2;
    map<pair<int,int>, int> dp;

    int solve(int i, int prev) {
        // All elements processed
        if (i == arr1.size())
            return 0;

        // Already calculated
        if (dp.count({i, prev}))
            return dp[{i, prev}];

        int op1 = 1e9;
        int op2 = 1e9;

        // Option 1: Don't replace arr1[i]
        if (arr1[i] > prev) {
            op1 = solve(i + 1, arr1[i]);
        }

        // Option 2: Replace arr1[i]
        // Find smallest element in arr2 > prev
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if (it != arr2.end()) {
            op2 = 1 + solve(i + 1, *it);
        }

        return dp[{i, prev}] = min(op1, op2);
    }

    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        arr1 = a;
        arr2 = b;

        sort(arr2.begin(), arr2.end());

        dp.clear();

        int ans = solve(0, -1);

        return ans >= 1e9 ? -1 : ans;
    }
};