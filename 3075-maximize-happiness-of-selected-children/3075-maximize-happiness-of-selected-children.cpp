class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long ans = 0;
        int cnt = 0;

        for (int i = happiness.size() - 1; i >= 0 && cnt < k; i--) {
            ans += max(0, happiness[i] - cnt);
            cnt++;
        }

        return ans;
    }
};