class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        int half = (n + 1) / 2;

        vector<int> part1, part2;

        // Smaller half
        for (int i = 0; i < half; i++) {
            part1.push_back(deck[i]);
        }

        // Larger half
        for (int i = half; i < n; i++) {
            part2.push_back(deck[i]);
        }

        vector<int> ans(n);

        queue<int> q;

        // Store positions, not values
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        int i = 0;
        int j = 0;

        // part1 + part2 values are assigned
        // according to actual reveal positions
        while (!q.empty()) {

            int pos = q.front();
            q.pop();

            if (i < part1.size()) {
                ans[pos] = part1[i++];
            }
            else {
                ans[pos] = part2[j++];
            }

            // Next top goes to bottom
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};