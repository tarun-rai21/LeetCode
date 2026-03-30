class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 100000;

    long long fact[100001], invFact[100001];

    long long power(long long x, long long y){
        long long res = 1;
        while(y){
            if(y & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    void precompute(){
        fact[0] = 1;
        for(int i = 1; i <= MAX; i++)
            fact[i] = (fact[i-1] * i) % MOD;

        invFact[MAX] = power(fact[MAX], MOD-2);

        for(int i = MAX-1; i >= 0; i--)
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }

    long long nCr(int n, int r){
        if(r > n || r < 0) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        precompute();

        int L = pos;
        int R = n - pos - 1;

        long long ans = 0;

        for(int x = 0; x <= k; x++){
            int y = k - x;

            if(x <= L && y <= R){
                ans = (ans + nCr(L, x) * nCr(R, y) % MOD) % MOD;
            }
        }

        return (2LL * ans) % MOD;
    }
};