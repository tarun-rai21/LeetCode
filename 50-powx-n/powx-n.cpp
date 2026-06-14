class Solution {
public:
    double myPow(double x, int N) {
        long long n = N;
        if(n<0){
            x = 1/x;
            n = -n;
        }
        
        if (n == 0) return 1;
        else if (n==1) return x;
        else {
            double half = myPow(x, n/2);

            if(n%2==0){
                //even power
                return half * half;
            }
            else{
                //odd power
                return x * half * half;
            }
        }
    }
};