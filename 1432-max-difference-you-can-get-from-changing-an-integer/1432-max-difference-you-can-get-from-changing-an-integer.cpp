class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Largest
        string mx = s;
        char ch = '#';
        for (char c : mx) {
            if (c != '9') {
                ch = c;
                break;
            }
        }
        if (ch != '#') {
            for (char &c : mx)
                if (c == ch)
                    c = '9';

        }

        // Smallest
        string mn = s;
        ch = '#';

        for (int i = 0; i < mn.size(); i++) {
            if (i == 0) {
                if (mn[i] != '1') {
                    ch = mn[i];
                    for (char &c : mn)
                        if (c == ch)
                            c = '1';
                    break;
                }
            } else {
                if (mn[i] != '0' && mn[i] != mn[0]) {
                    ch = mn[i];
                    for (char &c : mn)
                        if (c == ch)
                            c = '0';
                    break;
                }
            }
        }

        return stoi(mx) - stoi(mn);
    }
};