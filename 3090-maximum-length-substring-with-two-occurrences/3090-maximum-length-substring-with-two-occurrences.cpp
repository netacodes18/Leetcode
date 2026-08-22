class Solution {
public:
    int maximumLengthSubstring(string s) {

        unordered_map<char, int> mp;

        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {

            mp[s[j]]++;

            if (mp[s[j]] > 2) {

                // Keep removing from left
                // until we remove the first occurrence
                // of s[j]
                while (s[i] != s[j]) {
                    mp[s[i]]--;
                    i++;
                }

                // Remove the first occurrence of s[j]
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};