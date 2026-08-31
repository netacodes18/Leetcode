class Solution {
public:
    int n, m;
    int dp[101][101];

    bool solve(int i, int j, string &s1, string &s2, string &s3) {
        if (i == n && j == m) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int k = i + j;

        bool take1 = false;
        bool take2 = false;

        if (i < n && s1[i] == s3[k]) {
            take1 = solve(i + 1, j, s1, s2, s3);
        }

        if (j < m && s2[j] == s3[k]) {
            take2 = solve(i, j + 1, s1, s2, s3);
        }

        return dp[i][j] = take1 || take2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();

        if (n + m != s3.size()) {
            return false;
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s1, s2, s3);
    }
};