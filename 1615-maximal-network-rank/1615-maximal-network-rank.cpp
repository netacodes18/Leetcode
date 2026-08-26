class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n, 0);

        // Har city ki directly connected roads count karo
        for (auto &road : roads) {
            int a = road[0];
            int b = road[1];

            degree[a]++;
            degree[b]++;
        }

        int ans = 0;

        // Har pair of cities
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {

                int rank = degree[a] + degree[b];

                // Agar a-b ki direct road hai,
                // toh woh dono degree mein count ho chuki hai
                for (auto &road : roads) {
                    if ((road[0] == a && road[1] == b) ||
                        (road[0] == b && road[1] == a)) {
                        rank--;
                        break;
                    }
                }

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};