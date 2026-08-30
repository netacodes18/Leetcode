class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        int a = min(mn, mx);
        int b = max(mn, mx);

        int fromFront = b + 1;
        int fromBack = n - a;
        int oneEach = (a + 1) + (n - b);

        return min({fromFront, fromBack, oneEach});
    }
};