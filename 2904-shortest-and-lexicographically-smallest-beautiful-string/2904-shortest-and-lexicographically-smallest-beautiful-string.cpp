class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int count = 0;

        int i = 0;
        int j = 0;

        string ans = "";
        int minLen = INT_MAX;

        while (j < n) {
            if (s[j] == '1')
                count++;

            while (count >= k) {
                if (count == k) {
                    int len = j - i + 1;
                    string curr = s.substr(i, len);

                    if (len < minLen) {
                        minLen = len;
                        ans = curr;
                    }
                    else if (len == minLen && curr < ans) {
                        ans = curr;
                    }
                }

                if (s[i] == '1')
                    count--;

                i++;
            }

            j++;
        }

        return ans;
    }
};