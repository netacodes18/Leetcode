class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int x : arr)
            mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto &it : mp)
            pq.push({it.second, it.first});

        while (!pq.empty() && pq.top().first <= k) {
            k -= pq.top().first;
            pq.pop();
        }

        return pq.size();
    }
};