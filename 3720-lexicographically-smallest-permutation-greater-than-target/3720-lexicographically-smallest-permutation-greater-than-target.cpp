class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        vector<int> freq(26, 0);

        for (char x : s) {
            freq[x - 'a']++;
        }

        string per = "";

        // ----------------------------------------
        // Try to match target from left to right
        // ----------------------------------------
        for (int pos = 0; pos < n; pos++) {

            int cur = target[pos] - 'a';

            // Find smallest character >= target[pos]
            char firele = '{';

            for (int i = cur; i < 26; i++) {
                if (freq[i] > 0) {
                    firele = char('a' + i);
                    break;
                }
            }

            // Nothing >= target[pos]
            if (firele == '{') {
                break;
            }

            // If greater, directly construct answer
            if (firele > target[pos]) {

                per += firele;
                freq[firele - 'a']--;

                // Remaining characters ascending
                for (int i = 0; i < 26; i++) {
                    while (freq[i] > 0) {
                        per += char('a' + i);
                        freq[i]--;
                    }
                }

                return per;
            }

            // Equal -> keep matching
            per += firele;
            freq[firele - 'a']--;
        }

        // ----------------------------------------
        // We couldn't make answer greater yet.
        // Backtrack over ONLY matched characters.
        // ----------------------------------------

        int len = (int)per.length();

        for (int pos = len - 1; pos >= 0; pos--) {

            // Give back the character at this position
            freq[per[pos] - 'a']++;

            // Find smallest character > target[pos]
            char firele = '{';

            for (int i = target[pos] - 'a' + 1; i < 26; i++) {
                if (freq[i] > 0) {
                    firele = char('a' + i);
                    break;
                }
            }

            if (firele != '{') {

                string ans = per.substr(0, pos);

                // Put greater character here
                ans += firele;
                freq[firele - 'a']--;

                // Put remaining characters ascending
                for (int i = 0; i < 26; i++) {
                    while (freq[i] > 0) {
                        ans += char('a' + i);
                        freq[i]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};