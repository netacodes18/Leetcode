class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms,
                             vector<vector<int>>& queries) {
        
        // 1. Rooms ko size descending order mein sort karo
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });

        // query = {preferred, minSize, originalIndex}
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][0], queries[i][1], i});
        }

        // 2. Queries ko minSize descending order mein sort karo
        sort(q.begin(), q.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });

        vector<int> ans(queries.size(), -1);

        // Room IDs jo current minSize ko satisfy karte hain
        set<int> ids;

        int j = 0;

        // 3. Har query process karo
        for (auto &query : q) {

            int preferred = query[0];
            int minSize = query[1];
            int idx = query[2];

            // 4. Saare rooms add karo jinka size >= minSize hai
            while (j < rooms.size() && rooms[j][1] >= minSize) {
                ids.insert(rooms[j][0]);
                j++;
            }

            // Koi valid room nahi mila
            if (ids.empty())
                continue;

            // 5. preferred ke just >= ID ko find karo
            auto it = ids.lower_bound(preferred);

            // RIGHT candidate
            if (it != ids.end()) {
                ans[idx] = *it;
            }

            // LEFT candidate
            if (it != ids.begin()) {
                auto prevIt = prev(it);

                // Agar right candidate nahi hai
                // ya left candidate better/equally close hai
                if (it == ids.end() ||
                    abs(*prevIt - preferred) <= abs(*it - preferred)) {
                    ans[idx] = *prevIt;
                }
            }
        }

        return ans;
    }
};