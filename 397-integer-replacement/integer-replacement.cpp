class Solution {
public:

    int trailingZeroes(long long n) {
        if (n==0) return 0;
        return __builtin_ctz(n);
    }

    int integerReplacement(int num) {
        int count = 0;
        long long n = num;

        while(n!=1){
            if(n%2==0) n /= 2;
            else if(n == 3) n -= 1;
            else if(trailingZeroes(n-1) >= trailingZeroes(n+1)) n -= 1;
            else if(trailingZeroes(n-1) < trailingZeroes(n+1)) n += 1;
            else continue;

            count++;
        }

    return count;
    }
};