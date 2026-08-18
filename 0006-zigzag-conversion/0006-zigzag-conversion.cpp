class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        int n = s.length();

        // Maximum possible columns n
        vector<vector<char>> mat(numRows, vector<char>(n, ' '));

        int row = 0;
        int col = 0;
        int i = 0;

        bool down = true;

        while (i < n) {

            // Going DOWN
            if (down) {
                while (row < numRows && i < n) {
                    mat[row][col] = s[i++];
                    row++;
                }

                // We crossed the last row
                row -= 2;
                col++;
                down = false;
            }

            // Going DIAGONALLY UP
            else {
                while (row >= 0 && i < n) {
                    mat[row][col] = s[i++];
                    row--;
                    col++;
                }

                // We crossed the top row
                row = 1;
                down = true;
            }
        }

        // Read matrix row by row
        string ans = "";

        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] != ' ') {
                    ans += mat[r][c];
                }
            }
        }

        return ans;
    }
};