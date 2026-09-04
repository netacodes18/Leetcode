class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int evenRight = 0, oddRight = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                evenRight += nums[i];
            else
                oddRight += nums[i];
        }

        int evenLeft = 0, oddLeft = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // remove nums[i] from right
            if (i % 2 == 0)
                evenRight -= nums[i];
            else
                oddRight -= nums[i];

            // nums to the right shift parity
            int evenSum = evenLeft + oddRight;
            int oddSum = oddLeft + evenRight;

            if (evenSum == oddSum)
                ans++;

            // add nums[i] to left
            if (i % 2 == 0)
                evenLeft += nums[i];
            else
                oddLeft += nums[i];
        }

        return ans;
    }
};