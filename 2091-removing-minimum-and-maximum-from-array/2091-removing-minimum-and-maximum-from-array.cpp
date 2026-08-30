class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        // Find indices of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        // CASE 1:
        // Remove min from front + max from front
        int case1 = max(mn, mx) + 1;

        // CASE 2:
        // Remove min from back + max from back
        int case2 = n - min(mn, mx);

        // CASE 3:
        // Remove min from front + max from back
        int case3 = (mn + 1) + (n - mx);

        // CASE 4:
        // Remove max from front + min from back
        int case4 = (mx + 1) + (n - mn);

        return min({case1, case2, case3, case4});
    }
};