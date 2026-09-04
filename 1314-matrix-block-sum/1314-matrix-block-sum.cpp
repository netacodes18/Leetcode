class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        // Row prefix sum
        vector<vector<int>> r(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            r[i][0] = mat[i][0];

            for(int j = 1; j < m; j++) {
                r[i][j] = r[i][j-1] + mat[i][j];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int row1 = max(0, i-k);
                int row2 = min(n-1, i+k);

                int col1 = max(0, j-k);
                int col2 = min(m-1, j+k);

                for(int x = row1; x <= row2; x++) {

                    if(col1 == 0) {
                        ans[i][j] += r[x][col2];
                    }
                    else {
                        ans[i][j] += r[x][col2] - r[x][col1-1];
                    }
                }
            }
        }

        return ans;
    }
};