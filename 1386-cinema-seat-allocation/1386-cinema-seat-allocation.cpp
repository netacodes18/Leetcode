class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            rows[row] |= (1 << seat);
        }

        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {

            bool leftFree   = (mask & left) == 0;
            bool middleFree = (mask & middle) == 0;
            bool rightFree  = (mask & right) == 0;

            if (leftFree && rightFree) {
                ans += 2;
            }
            else if (leftFree || middleFree || rightFree) {
                ans += 1;
            }
        }

        return ans;
    }
};