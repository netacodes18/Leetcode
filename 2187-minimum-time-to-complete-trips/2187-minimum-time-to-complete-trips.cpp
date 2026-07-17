class Solution {
public:
    long long countTrips(vector<int>& time, long long currTime) {
        long long trips = 0;

        for (int t : time) {
            trips += currTime / t;
        }

        return trips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countTrips(time, mid) >= totalTrips) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};