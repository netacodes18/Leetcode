class Solution {
public:
    bool allMarked(int t, vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();

        vector<int> lastIdxPos(n + 1, -1);

        for (int i = 0; i < t; i++)
            lastIdxPos[changeIndices[i]] = i;

        vector<pair<int, int>> order;

        for (int i = 1; i <= n; i++) {
            if (lastIdxPos[i] == -1)
                return false;
            order.push_back({lastIdxPos[i], i});
        }

        sort(order.begin(), order.end());

        int reqTime = 0;
        int marked = 0;

        for (auto &it : order) {
            int lastPos = it.first;
            int idx = it.second;

            reqTime += nums[idx - 1];

            int timePassed = lastPos - marked;

            if (reqTime > timePassed)
                return false;

            marked++;
        }

        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m = changeIndices.size();

        for (int t = 1; t <= m; t++) {
            if (allMarked(t, nums, changeIndices))
                return t;
        }

        return -1;
    }
};