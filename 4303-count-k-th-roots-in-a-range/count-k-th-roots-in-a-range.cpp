class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        long long left = ceil(pow(l, 1.0/k) - 1e-9);
        long long right = floor(pow(r, 1.0/k) + 1e-9);

        return max(0LL, right-left+1);
    }
};