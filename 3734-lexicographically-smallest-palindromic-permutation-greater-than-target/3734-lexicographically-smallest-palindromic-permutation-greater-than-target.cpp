class Solution {
public:
    int halfn = 0;
    char mid = '$';
    string result = "";

    bool solve(string& curr, string& target, int i,
               vector<int>& freq, bool isgreater) {

        if (curr.length() == halfn) {
            string candidate = curr;

            if (mid != '$')
                candidate += mid;

            string rest = curr;
            reverse(rest.begin(), rest.end());

            candidate += rest;

            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c - 'a'] == 0)
                continue;

            if (!isgreater && c < target[i])
                continue;

            curr.push_back(c);
            freq[c - 'a']--;

            bool newGreater = isgreater || (c > target[i]);

            if (solve(curr, target, i + 1, freq, newGreater))
                return true;

            curr.pop_back();
            freq[c - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int oddcount = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                oddcount++;
                mid = 'a' + i;
            }
        }

        if (oddcount > 1)
            return "";

        halfn = s.length() / 2;

        for (int i = 0; i < 26; i++)
            freq[i] /= 2;

        string curr = "";

        solve(curr, target, 0, freq, false);

        return result;
    }
};