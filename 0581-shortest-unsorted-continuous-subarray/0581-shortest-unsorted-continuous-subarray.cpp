class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int s = -1, e = -1;

        // Find first inversion from left
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                s = i;
                break;
            }
        }

        // Already sorted
        if (s == -1) return 0;

        // Find first inversion from right
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                e = i;
                break;
            }
        }

        // Find min and max in the unsorted region
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = s; i <= e; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        // Expand left boundary
        while (s > 0 && nums[s - 1] > mn)
            s--;

        // Expand right boundary
        while (e < n - 1 && nums[e + 1] < mx)
            e++;

        return e - s + 1;
    }
};