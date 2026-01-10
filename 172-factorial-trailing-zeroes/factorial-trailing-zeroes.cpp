// Solved by Tarun

class Solution {
public:
    int trailingZeroes(int n) {
        int trailingZeros = 0;

        while(n>0){
            n/=5;
            trailingZeros+=n;
        }

        return trailingZeros;
    }
};