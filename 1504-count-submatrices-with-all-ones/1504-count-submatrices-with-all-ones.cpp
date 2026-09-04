class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> nums(n, 0);

        int ans = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Continuous 1s ending at current cell
                if (mat[i][j] == 0)
                    nums[j] = 0;
                else
                    nums[j]++;

                int mn = INT_MAX;

                // Expand left
                for (int k = j; k >= 0; k--) {

                    mn = min(mn, nums[k]);

                    ans += mn;
                }
            }
        }

        return ans;
    }
};