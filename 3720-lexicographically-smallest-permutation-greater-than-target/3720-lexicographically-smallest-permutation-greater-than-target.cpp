class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        vector<int> freq(26, 0);

        for(char x : s)
            freq[x - 'a']++;

        for(int i = n - 1; i >= 0; i--) {
            for(int ch = target[i] - 'a' + 1; ch < 26; ch++) {

                if(freq[ch] == 0)
                    continue;

                freq[ch]--;  // FIXED: ch is already 0-25, so use freq[ch]

                int temp[26];

                for(int j = 0; j < 26; j++)
                    temp[j] = freq[j];

                bool allfound = true;  // FIXED: assume left part is possible initially

                for(int k = 0; k < i; k++) {
                    int x = target[k] - 'a';

                    if(temp[x] == 0) {
                        allfound = false;
                        break;
                    }

                    temp[x]--;  // FIXED: decrement x (character index), not k
                }

                if(allfound) {
                    string ans = target.substr(0, i);

                    ans += char('a' + ch);

                    for(int j = 0; j < i; j++)
                        freq[target[j] - 'a']--;

                    for(int p = 0; p < 26; p++) {
                        while(freq[p] > 0) {
                            ans += char('a' + p);  // FIXED: removed extra "ans +="
                            freq[p]--;            // FIXED: decrement inside while
                        }
                    }

                    return ans;
                }

                freq[ch]++;  // restore chosen character if it didn't work
            }
        }

        return "";
    }
};