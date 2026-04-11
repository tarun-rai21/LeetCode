class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans = 0;
        if(n==1) return ++ans;
        else return 1/(ans+2);
    }
};