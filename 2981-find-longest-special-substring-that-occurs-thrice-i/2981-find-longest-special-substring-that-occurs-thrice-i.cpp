class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        for (char c = 'a'; c <= 'z'; c++) {
            vector<int> runs;

            for (int i = 0; i < n; ) {
                if (s[i] != c) {
                    i++;
                    continue;
                }

                int j = i;
                while (j < n && s[j] == c) j++;

                runs.push_back(j - i);
                i = j;
            }

            // Try every possible length
            for (int len = 1; len <= n; len++) {
                int cnt = 0;

                for (int x : runs) {
                    if (x >= len)
                        cnt += x - len + 1;
                }

                if (cnt >= 3)
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};