class Solution { 
public: 
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) { 
        vector<vector<int>> grid(n, vector<int>(n, 1)); 
        
        for(auto mine : mines) {
            int x = mine[0];
            int y = mine[1];
            grid[x][y] = 0;
        }

        vector<vector<int>> dp(n, vector<int>(n, n)); 

        // Left
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    count++;
                else
                    count = 0;

                dp[i][j] = min(dp[i][j], count);
            }
        }

        // Right
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n-1; j >= 0; j--) {
                if(grid[i][j] == 1)
                    count++;
                else
                    count = 0;

                dp[i][j] = min(dp[i][j], count);
            }
        }

        // Up
        for(int j = 0; j < n; j++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 1)
                    count++;
                else
                    count = 0;

                dp[i][j] = min(dp[i][j], count);
            }
        }

        // Down
        for(int j = 0; j < n; j++) {
            int count = 0;
            for(int i = n-1; i >= 0; i--) {
                if(grid[i][j] == 1)
                    count++;
                else
                    count = 0;

                dp[i][j] = min(dp[i][j], count);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    } 
};