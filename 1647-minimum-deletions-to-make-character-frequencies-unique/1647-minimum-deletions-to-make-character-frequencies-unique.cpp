class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;

        // Count frequency
        for (char c : s)
            mp[c]++;

        vector<pair<char, int>> freq;
        for (auto &it : mp)
            freq.push_back(it);

        int ans = 0;

        // Process every character
        for (int i = 0; i < freq.size(); i++) {

            while (freq[i].second > 0) {

                bool found = false;

                // Check if any other character has same frequency
                for (int j = 0; j < freq.size(); j++) {

                    if (i == j)
                        continue;

                    if (freq[i].second == freq[j].second) {
                        freq[i].second--;
                        ans++;
                        found = true;
                        break;
                    }
                }

                if (!found)
                    break;
            }
        }

        return ans;
    }
};