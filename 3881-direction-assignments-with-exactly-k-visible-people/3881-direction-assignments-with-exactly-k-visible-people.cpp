class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    long long nCr(long long n, long long r) {
        if (r < 0 || r > n)
            return 0;

        long long num = 1;
        long long den = 1;

        for (long long i = 0; i < r; i++) {
            num = num * (n - i) % MOD;
            den = den * (i + 1) % MOD;
        }

        return num * power(den, MOD - 2) % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        if (k > n - 1)
            return 0;

        return 2 * nCr(n - 1, k) % MOD;
    }
};