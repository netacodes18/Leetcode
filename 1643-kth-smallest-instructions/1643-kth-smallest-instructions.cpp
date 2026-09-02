class Solution {
public:

    long long comb(int n, int r) {
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
        }

        return ans;
    }

    string kthSmallestPath(vector<int>& destination, int k) {

        int v = destination[0];  // V moves
        int h = destination[1];  // H moves

        string ans = "";

        for (int i = 0; i < destination[0] + destination[1]; i++) {

            if (h == 0) {
                ans += 'V';
                continue;
            }

            if (v == 0) {
                ans += 'H';
                continue;
            }

            // H choose karne par possible paths
            long long cnt = comb(h + v - 1, v);

            if (cnt >= k) {
                ans += 'H';
                h--;
            }
            else {
                ans += 'V';
                v--;
                k -= cnt;
            }
        }

        return ans;
    }
};