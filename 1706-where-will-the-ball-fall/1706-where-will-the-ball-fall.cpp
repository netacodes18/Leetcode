class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        if (row == m) {
            return col;
        }

        if (grid[row][col] == 1) {
            if (col + 1 >= n || grid[row][col + 1] == -1) {
                return -1;
            }

            return dfs(grid, row + 1, col + 1);
        }
        else {

            if (col - 1 < 0 || grid[row][col - 1] == 1) {
                return -1;
            }

            return dfs(grid, row + 1, col - 1);
        }
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);

        for (int col = 0; col < n; col++) {
            ans[col] = dfs(grid, 0, col);
        }

        return ans;
    }
};