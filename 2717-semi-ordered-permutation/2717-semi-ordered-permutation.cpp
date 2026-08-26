class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();

        int pos1 = 0, posN = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                pos1 = i;

            if (nums[i] == n)
                posN = i;
        }

        int ans = pos1 + (n - 1 - posN);

        // n is before 1, so one swap is counted twice
        if (pos1 > posN)
            ans--;

        return ans;
    }
};