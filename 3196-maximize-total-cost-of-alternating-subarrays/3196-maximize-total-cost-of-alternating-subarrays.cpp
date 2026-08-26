class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long dp0 = nums[0];
        long long dp1 = LLONG_MIN / 2;

        for (int i = 1; i < nums.size(); i++) {
            long long new_dp0 = max(dp0, dp1) + nums[i];
            long long new_dp1 = dp0 - nums[i];

            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        return max(dp0, dp1);
    }
};