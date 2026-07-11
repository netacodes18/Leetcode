class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;

        for(char c : s) mp[c]++;

        vector<pair<char,int>> freq;
        for(auto it : mp) freq.push_back(it);

        int ans = 0;

        for(int i = 0; i < freq.size(); i++) {

            while(freq[i].second > 0) {

                int j;
                for(j = 0; j < freq.size(); j++) {
                    if(i == j) continue;

                    if(freq[i].second == freq[j].second) {
                        freq[i].second--;
                        ans++;
                        break;
                    }
                }

                if(j == freq.size())
                    break;
            }
        }

        return ans;
    }
};