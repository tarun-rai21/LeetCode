//solved by Tarun

class Solution {
public:
    int reverseBits(int n) {
        int ans=0;

        for(int i=0; i<32; i++){
            ans <<= 1;             //create empty space
            ans = ans | (n & 1);   //extract last bit from n and put in ans
            n >>= 1;               //right shift num by 1
        }

        return ans;
    }
};