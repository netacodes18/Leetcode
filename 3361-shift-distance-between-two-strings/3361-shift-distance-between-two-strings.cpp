class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            long long forward = 0;
            int curr = a;

            while (curr != b) {
                forward += nextCost[curr];
                curr = (curr + 1) % 26;
            }

            long long backward = 0;
            curr = a;

            while (curr != b) {
                backward += previousCost[curr];
                curr = (curr - 1 + 26) % 26;
            }

            ans += min(forward, backward);
        }

        return ans;
    }
};