class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // store values in sorted order along with positions using ordered map
        map<int, vector<pair<int, int>>> mp;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mp[grid[i][j]].push_back({i, j});

        // dp to store max score for each position
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // vectors to store rowMaxScore and colMaxScore
        vector<int> rowMaxScore(m, 0);
        vector<int> colMaxScore(n, 0);

        // scan ordered map - keys will be in increasing order
        for (auto& [val, pos] : mp) {

            // update dp score - handle all duplicates together
            for (auto it : pos) {
                int i = it.first;
                int j = it.second;

                dp[i][j] = max(rowMaxScore[i], colMaxScore[j]) + 1;
            }

            // update rowMaxScore and colMaxScore
            for (auto it : pos) {
                int i = it.first;
                int j = it.second;

                rowMaxScore[i] = max(rowMaxScore[i], dp[i][j]);
                colMaxScore[j] = max(colMaxScore[j], dp[i][j]);
            }
        }

        // find maximum score
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};