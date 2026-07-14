class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Maximum number
        string mx = s;
        char x = 0;
        for (char c : mx) {
            if (c != '9') {
                x = c;
                break;
            }
        }
        if (x) {
            for (char &c : mx)
                if (c == x) c = '9';
        }

        // Minimum number
        string mn = s;
        if (mn[0] != '1') {
            x = mn[0];
            for (char &c : mn)
                if (c == x) c = '1';
        } else {
            x = 0;
            for (int i = 1; i < mn.size(); i++) {
                if (mn[i] != '0' && mn[i] != '1') {
                    x = mn[i];
                    break;
                }
            }
            if (x) {
                for (char &c : mn)
                    if (c == x) c = '0';
            }
        }

        return stoi(mx) - stoi(mn);
    }
};