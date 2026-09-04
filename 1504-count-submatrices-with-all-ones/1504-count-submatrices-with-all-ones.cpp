class Solution {
public:

    int countOnes(vector<int>& vec) {
        int ans = 0;
        int cnt = 0;

        for (int x : vec) {
            if (x == 1)
                cnt++;
            else
                cnt = 0;

            ans += cnt;
        }

        return ans;
    }

    int numSubmat(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;

        for (int sr = 0; sr < n; sr++) {

            vector<int> vec(m, 1);

            for (int er = sr; er < n; er++) {

                for (int col = 0; col < m; col++) {
                    vec[col] &= mat[er][col];
                }

                ans += countOnes(vec);
            }
        }

        return ans;
    }
};