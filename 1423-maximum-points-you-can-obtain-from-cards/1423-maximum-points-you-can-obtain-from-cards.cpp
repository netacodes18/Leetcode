class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(k + 1, 0), suffix(k + 1, 0);

        for (int i = 0; i < k; ++i) {
            prefix[i + 1] = prefix[i] + cardPoints[i];
            suffix[i + 1] = suffix[i] + cardPoints[n - 1 - i];
        }

        int maxPoints = 0;
        for (int i = 0; i <= k; ++i) {
            maxPoints = max(maxPoints, prefix[i] + suffix[k - i]);
        }

        return maxPoints;
    }
};