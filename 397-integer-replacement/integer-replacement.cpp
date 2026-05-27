class Solution {
public:

    int countTrailingZeros(long long n) {
        return __builtin_ctzll(n);
    }

    int integerReplacement(int num) {
        long long n = num;
        int steps = 0;

        while (n != 1) {

            // even
            if ((n & 1) == 0) {
                n >>= 1;
            }

            // odd
            else if (n == 3 || countTrailingZeros(n - 1) > countTrailingZeros(n + 1)) {
                n--;
            }
            else {
                n++;
            }

            steps++;
        }

        return steps;
    }
};