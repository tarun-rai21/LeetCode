class Solution {
public:
const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        const int MOD = 1e9+7;
        long long odd_indices = n/2;  //number of odd indices
        long long even_indices = n - odd_indices; // number of even indices

        return power(5, even_indices)*power(4, odd_indices)%MOD;
    }
};