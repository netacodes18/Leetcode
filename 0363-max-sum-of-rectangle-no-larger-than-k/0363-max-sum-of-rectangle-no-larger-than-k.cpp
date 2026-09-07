class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int res = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int l = 0; l < cols; l++) {

            vector<int> sums(rows, 0);

            for (int r = l; r < cols; r++) {

                // Compress 2D into 1D
                for (int i = 0; i < rows; i++) {
                    sums[i] += matrix[i][r];
                }

                // Maximum subarray sum <= k
                set<int> s;
                s.insert(0);

                int run_sum = 0;

                for (int sum : sums) {

                    run_sum += sum;

                    auto it = s.lower_bound(run_sum - k);

                    if (it != s.end()) {
                        res = max(res, run_sum - *it);
                    }

                    s.insert(run_sum);
                }
            }
        }

        return res;
    }
};