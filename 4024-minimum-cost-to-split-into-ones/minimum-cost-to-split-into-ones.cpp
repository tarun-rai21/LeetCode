class Solution {
public:
    int minCost(int n) {
        return n*(n-1)/2;   //sum of digits till n-1
    }
};