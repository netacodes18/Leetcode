class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        // 1. First and last occurrence of every character
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // 2. Create a valid interval for every character
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            // 3. Expand the interval
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // Character occurs before l -> invalid
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Include all occurrences of this character
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // 4. Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        // 5. Greedily select non-overlapping intervals
        vector<string> ans;

        int lastEnd = -1;

        for (auto [l, r] : intervals) {

            if (l > lastEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }

        return ans;
    }
};