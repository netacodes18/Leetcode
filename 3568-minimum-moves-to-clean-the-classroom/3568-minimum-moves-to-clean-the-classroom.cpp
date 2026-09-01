class Solution {
public:
    int dirx[4] = {0, 1, -1, 0};
    int diry[4] = {1, 0, 0, -1};

    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        // Give every litter an index
        vector<vector<int>> id(n, vector<int>(m, -1));

        int sx = -1, sy = -1;
        int litterCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // All litters collected
        int fullMask = (1 << litterCount) - 1;

        // state = {x, y, currentEnergy, mask}
        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, 0});

        // visited[x][y][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        visited[sx][sy][energy][0] = true;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dirx[d];
                    int ny = y + diry[d];

                    // Outside grid
                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= m)
                        continue;

                    // Wall
                    if (classroom[nx][ny] == 'X')
                        continue;

                    // Cannot move with 0 energy
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // If this cell has litter
                    if (classroom[nx][ny] == 'L') {
                        int idx = id[nx][ny];

                        nmask |= (1 << idx);
                    }

                    // Recharge
                    if (classroom[nx][ny] == 'R') {
                        ne = energy;
                    }

                    // Already visited
                    if (visited[nx][ny][ne][nmask])
                        continue;

                    visited[nx][ny][ne][nmask] = true;

                    q.push({nx, ny, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};