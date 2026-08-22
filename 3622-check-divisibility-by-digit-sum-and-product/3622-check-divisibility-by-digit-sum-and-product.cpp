class Solution {
public:

    bool checkDivisibility(int n) {

        string s = to_string(n);

        int sum = 0;
        int prod = 1;

        for (char x : s) {
            int digit = x - '0';

            sum += digit;
            prod *= digit;
        }

        return n % (sum + prod) == 0;
    }
};