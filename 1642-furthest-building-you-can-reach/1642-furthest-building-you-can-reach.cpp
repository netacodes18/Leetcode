class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = heights.size();

        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0)
                continue;

            // Temporarily assign a ladder
            minHeap.push(diff);

            // More climbs than ladders -> smallest climb uses bricks
            if (minHeap.size() > ladders) {
                bricks -= minHeap.top();
                minHeap.pop();
            }

            // Not enough bricks
            if (bricks < 0)
                return i;
        }

        return n - 1;
    }
};