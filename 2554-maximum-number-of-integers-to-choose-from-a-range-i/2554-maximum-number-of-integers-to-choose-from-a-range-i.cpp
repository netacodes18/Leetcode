class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());

        int cnt = 0;
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;

            if (sum + i > maxSum) break;

            sum += i;
            cnt++;
        }

        return cnt;
    }
};