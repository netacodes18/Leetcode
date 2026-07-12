class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = 0;

        for (auto &it : mp) {
            int freq = it.second;

            if (freq == 1)
                return -1;

            while (freq > 4) {
                freq -= 3;
                ans++;
            }

            if (freq == 4)
                ans += 2;
            else if (freq == 3)
                ans += 1;
            else if (freq == 2)
                ans += 1;
        }

        return ans;
    }
};