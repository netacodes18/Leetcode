class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();

        int ans = 0;

        for (int i = 1; i < arrays.size(); i++) {
            int currMin = arrays[i][0];
            int currMax = arrays[i].back();

            ans = max(ans, currMax - globalMin);
            ans = max(ans, globalMax - currMin);

            globalMin = min(globalMin, currMin);
            globalMax = max(globalMax, currMax);
        }

        return ans;
    }
};