class Solution {
public:
    vector<int> dp;
    vector<int> squares;

    bool solve(int n) {
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int sq : squares) {
            if (sq > n)
                break;

            // Opponent losing state mein chala gaya
            if (!solve(n - sq)) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);

        // Store all perfect squares <= n
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        return solve(n);
    }
};