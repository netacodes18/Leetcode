class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        int even = 0;
        int odd = 1;

        for (int i = 0; i < n; i++) {
            sumOdd += odd;
            odd += 2;

            sumEven += even;
            even += 2;
        }

        return gcd(sumOdd, sumEven);
    }
};