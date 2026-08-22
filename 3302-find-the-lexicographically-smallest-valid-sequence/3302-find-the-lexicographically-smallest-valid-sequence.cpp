class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> right(n);

        int i = n - 1;
        int j = m - 1;
        int rMatch = 0;

        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rMatch++;
                j--;
            }

            right[i] = rMatch;
            i--;
        }

        vector<int> seq;
        bool canChange = true;

        i = 0;
        j = 0;

        while (i < n && j < m) {

            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            }
            else if (canChange &&
                     (i + 1 == n || right[i + 1] >= m - j - 1)) {

                seq.push_back(i);
                j++;
                canChange = false;
            }

            i++;
        }

        return j == m ? seq : vector<int>();
    }
};