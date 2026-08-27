class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        int n = target.size();

        for (int i = n - 1; i >= 0; i--) {
            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {

                if (freq[ch] == 0)
                    continue;

                freq[ch]--;

                int temp[26];
                for (int k = 0; k < 26; k++)
                    temp[k] = freq[k];

                bool allFoundLeft = true;

                for (int j = 0; j < i; j++) {
                    int x = target[j] - 'a';

                    if (temp[x] == 0) {
                        allFoundLeft = false;
                        break;
                    }

                    temp[x]--;
                }

                if (allFoundLeft) {
                    string ans = target.substr(0, i);
                    ans += char('a' + ch);

                    for (int j = 0; j < i; j++)
                        freq[target[j] - 'a']--;

                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }

                freq[ch]++;
            }
        }

        return "";
    }
};