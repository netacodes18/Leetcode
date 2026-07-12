class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for (char ch : word)
            freq[ch - 'a']++;

        int ans = word.size();

        for (int x : freq) {
            if (x == 0) continue;

            int del = 0;

            for (int f : freq) {
                if (f == 0) continue;

                if (f < x)
                    del += f;
                else if (f > x + k)
                    del += f - (x + k);
            }

            ans = min(ans, del);
        }

        return ans;
    }
};