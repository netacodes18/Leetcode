class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms, int target) {
        int topRot = 0, bottomRot = 0;

        for (int i = 0; i < tops.size(); i++) {
            // Impossible to make this domino contain target
            if (tops[i] != target && bottoms[i] != target)
                return INT_MAX;

            // Rotate if top is not target
            if (tops[i] != target)
                topRot++;

            // Rotate if bottom is not target
            if (bottoms[i] != target)
                bottomRot++;
        }

        return min(topRot, bottomRot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(check(tops, bottoms, tops[0]),
                      check(tops, bottoms, bottoms[0]));

        return (ans == INT_MAX) ? -1 : ans;
    }
};