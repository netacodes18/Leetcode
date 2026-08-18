class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int parts, string current) {

        // 4 parts ban gaye
        if (parts == 4) {
            // Saare digits use ho gaye
            if (index == s.size()) {
                current.pop_back(); // last extra '.'
                ans.push_back(current);
            }
            return;
        }

        // Try 1, 2, 3 digits
        for (int len = 1; len <= 3; len++) {

            // String ke bahar chale gaye
            if (index + len > s.size())
                break;

            // Leading zero: "01", "00" invalid
            if (len > 1 && s[index] == '0')
                break;

            // Number banao
            string part = s.substr(index, len);

            // 255 se bada hai
            if (stoi(part) > 255)
                break;

            // Next part ke liye recursion
            solve(s, index + len, parts + 1,
                 current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};