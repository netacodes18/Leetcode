class Solution {
public:
    unordered_map<long long, bool> dp;
    unordered_set<int> st;
    int last;

    bool dfs(int currpos, int prevMove, vector<int>& stones) {
        if (currpos == last)
            return true;

        long long key = ((long long)currpos << 32) | prevMove;

        if (dp.count(key))
            return dp[key];

        int next1 = currpos + prevMove - 1;
        int next2 = currpos + prevMove;
        int next3 = currpos + prevMove + 1;

        bool ans =
            (prevMove > 1 && st.count(next1) &&
             dfs(next1, prevMove - 1, stones))
            ||
            (st.count(next2) &&
             dfs(next2, prevMove, stones))
            ||
            (st.count(next3) &&
             dfs(next3, prevMove + 1, stones));

        return dp[key] = ans;
    }

    bool canCross(vector<int>& stones) {
        last = stones.back();

        for (int x : stones)
            st.insert(x);

        if (stones.size() < 2 || stones[1] != 1)
            return false;

        return dfs(1, 1, stones);
    }
};