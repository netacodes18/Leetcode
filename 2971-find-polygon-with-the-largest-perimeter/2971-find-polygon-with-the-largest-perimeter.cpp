class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        for (int x : nums)
            sum += x;

        int cnt = nums.size();

        for (int i = nums.size() - 1; i >= 0 && cnt >= 3; i--) {
            if (sum - nums[i] > nums[i])
                return sum;

            sum -= nums[i];
            cnt--;
        }

        return -1;
    }
};