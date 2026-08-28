class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();

        vector<int> best(n + 1, 0);

        int ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            while (prizePositions[right] - prizePositions[left] > k)
                left++;

            int cnt = right - left + 1;

            // Best ONE segment so far
            best[right + 1] = max(best[right], cnt);

            // Current segment + best segment before it
            ans = max(ans, best[left] + cnt);
        }

        return ans;
    }
};