class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Store reserved seats row-wise
        map<int, set<int>> grid;
        set<int> reservedRows;

        for (vector<int> x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            grid[row].insert(seat);
            reservedRows.insert(row);
        }

        int ans = (n - reservedRows.size()) * 2;

        for (int row : reservedRows) {

            bool left = true;   
            bool middle = true; 
            bool right = true;  

            for (int seat = 2; seat <= 5; seat++) {
                if (grid[row].count(seat)) {
                    left = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (grid[row].count(seat)) {
                    middle = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (grid[row].count(seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};