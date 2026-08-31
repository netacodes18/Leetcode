class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // LIS ending at i
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }

        // LDS starting at i
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }

        int longestMountain = 0;

        for (int i = 1; i < n - 1; i++) {
            // Peak must have elements on both sides
            if (left[i] > 1 && right[i] > 1) {
                longestMountain = max(
                    longestMountain,
                    left[i] + right[i] - 1
                );
            }
        }

        return n - longestMountain;
    }
};