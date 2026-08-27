class Solution {
public:
    /*
    Binary search on the answer (radius).

    low = 0
    high = maximum distance that can possibly be required

    For every mid:
    - if all houses can be covered -> try smaller radius
    - otherwise -> try larger radius
    */

    bool canCover(vector<int>& houses, vector<int>& heaters, int radius) {
        int i = 0;
        int j = 0;

        while (j < heaters.size()) {
            int upper = heaters[j] + radius;
            int lower = heaters[j] - radius;

            while (i < houses.size() &&
                   houses[i] >= lower &&
                   houses[i] <= upper) {
                i++;
            }

            j++;
        }

        return i == houses.size();
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int low = 0;

        // Maximum possible distance that may be required.
        int high = max(
            abs(houses.front() - heaters.back()),
            abs(houses.back() - heaters.front())
        );

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canCover(houses, heaters, mid)) {
                // mid works, try to find a smaller radius
                ans = mid;
                high = mid - 1;
            }
            else {
                // mid is not enough
                low = mid + 1;
            }
        }

        return ans;
    }
};