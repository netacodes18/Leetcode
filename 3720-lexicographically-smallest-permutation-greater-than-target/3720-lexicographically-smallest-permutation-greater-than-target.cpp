class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        vector<int> freq(26, 0);

        for (char x : s) {
            freq[x - 'a']++;
        }

        string per = "";

        for (int pos = 0; pos < n; pos++) {

            int cur = target[pos] - 'a';

            char firele = '{';

            for (int i = cur; i < 26; i++) {
                if (freq[i] > 0) {
                    firele = char('a' + i);
                    break;
                }
            }

            if (firele == '{') {
                break;
            }

            if (firele > target[pos]) {

                per += firele;
                freq[firele - 'a']--;

                for (int i = 0; i < 26; i++) {
                    while (freq[i] > 0) {
                        per += char('a' + i);
                        freq[i]--;
                    }
                }

                return per;
            }

            per += firele;
            freq[firele - 'a']--;
        }

        int len = (int)per.length();

        for (int pos = len - 1; pos >= 0; pos--) {

            freq[per[pos] - 'a']++;

            char firele = '{';

            for (int i = target[pos] - 'a' + 1; i < 26; i++) {
                if (freq[i] > 0) {
                    firele = char('a' + i);
                    break;
                }
            }

            if (firele != '{') {

                string ans = per.substr(0, pos);

                ans += firele;
                freq[firele - 'a']--;

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