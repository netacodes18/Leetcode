class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int water = capacity;

        for (int i = 0; i < plants.size(); i++) {
            // Agar current plant ko water karne ke liye paani nahi hai
            if (water < plants[i]) {
                steps += 2 * i;   // Plant i-1 -> River -> Plant i
                water = capacity;
            }

            // Current plant tak ek step
            steps++;
            water -= plants[i];
        }

        return steps;
    }
};