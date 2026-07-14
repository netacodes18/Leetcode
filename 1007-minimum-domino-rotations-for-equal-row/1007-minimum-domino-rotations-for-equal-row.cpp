class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms, int target) {
        int topRot = 0, bottomRot = 0;

        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != target && bottoms[i] != target)
                return INT_MAX;

            if (tops[i] != target) topRot++;
            if (bottoms[i] != target) bottomRot++;
        }

        return min(topRot, bottomRot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;

        for (int target = 1; target <= 6; target++) {
            ans = min(ans, check(tops, bottoms, target));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};