class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i - 1].first <= limit) {
                unite(v[i].second, v[i - 1].second);
            }
        }

        unordered_map<int, vector<int>> indices;
        unordered_map<int, vector<int>> values;

        for (int i = 0; i < n; i++) {
            int root = find(i);

            indices[root].push_back(i);
            values[root].push_back(nums[i]);
        }

        vector<int> ans = nums;

        for (auto& [root, idx] : indices) {
            auto& vals = values[root];

            sort(idx.begin(), idx.end());
            sort(vals.begin(), vals.end());

            for (int i = 0; i < idx.size(); i++) {
                ans[idx[i]] = vals[i];
            }
        }

        return ans;
    }
};