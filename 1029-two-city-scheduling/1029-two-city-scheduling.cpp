class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        // (difference, (A_cost, B_cost))
        vector<pair<int, pair<int, int>>> v;

        for (auto &x : costs) {
            int diff = x[0] - x[1];
            v.push_back({diff, {x[0], x[1]}});
        }

        // Sort by difference (A - B)
        sort(v.begin(), v.end());

        int n = costs.size() / 2;
        int ans = 0;

        // First n people -> City A
        for (int i = 0; i < n; i++) {
            ans += v[i].second.first;
        }

        // Remaining n people -> City B
        for (int i = n; i < 2 * n; i++) {
            ans += v[i].second.second;
        }

        return ans;
    }
};