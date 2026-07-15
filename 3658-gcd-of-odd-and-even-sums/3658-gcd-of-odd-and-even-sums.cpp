#include <numeric>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n * n, n * (n - 1));
    }
};