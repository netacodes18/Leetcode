class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        int moves = 0;

        auto it = mp.begin();

        while (it != mp.end()) {
            int val = it->first;
            int freq = it->second;

            if (freq > 1) {
                int extra = freq - 1;

                moves += extra;      // extra elements move by +1
                mp[val + 1] += extra;
                it->second = 1;
            }

            ++it;
        }

        return moves;
    }
};