class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        long long ans = 0;
        long long horizontalPieces = 1, verticalPieces = 1;

        int i = 0, j = 0;

        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                ans += 1LL * horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                ans += 1LL * verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        while (i < horizontalCut.size()) {
            ans += 1LL * horizontalCut[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }

        while (j < verticalCut.size()) {
            ans += 1LL * verticalCut[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }

        return ans;
    }
};