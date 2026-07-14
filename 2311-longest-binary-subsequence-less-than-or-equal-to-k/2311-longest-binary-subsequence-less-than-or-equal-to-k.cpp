class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int ans = 0;
        long long value = 0;
        long long power = 1;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ans++;  // Always take 0
            } else {
                if (value + power <= k) {
                    value += power;
                    ans++;
                }
            }

            if (power <= k)
                power <<= 1;
        }

        return ans;
    }
};