class Solution {
public:
    int n, m;

    unordered_map<int, vector<pair<int,int>>> directions = {
        {1, {{0,-1}, {0,1}}},      // left, right
        {2, {{-1,0}, {1,0}}},      // up, down
        {3, {{0,-1}, {1,0}}},      // left, down
        {4, {{0,1}, {1,0}}},       // right, down
        {5, {{0,-1}, {-1,0}}},     // left, up
        {6, {{-1,0}, {0,1}}}       // up, right
    };

    bool dfs(int i, int j,
             vector<vector<bool>>& visited,
             vector<vector<int>>& grid) {

        if(i == n-1 && j == m-1)
            return true;

        visited[i][j] = true;

        // current cell ki saari possible directions
        for(auto &dir : directions[grid[i][j]]) {

            int ni = i + dir.first;
            int nj = j + dir.second;

            // boundary + visited check
            if(ni < 0 || ni >= n ||
               nj < 0 || nj >= m ||
               visited[ni][nj])
                continue;

            // check karo ki next cell wapas current tak aa sakta hai ya nahi
            for(auto &backDir : directions[grid[ni][nj]]) {

                if(ni + backDir.first == i &&
                   nj + backDir.second == j) {

                    if(dfs(ni, nj, visited, grid))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        return dfs(0, 0, visited, grid);
    }
};