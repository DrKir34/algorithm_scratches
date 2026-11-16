#include <vector>
#include <cassert>
#include <algorithm>

template <long long MOD = 1'000'000'007LL>
class Math {
public:
    explicit Math(int N) : N_(N) {
        fact_.resize(N_ + 1);
        invfact_.resize(N_ + 1);

        fact_[0] = 1;
        for (int i = 1; i <= N_; ++i) fact_[i] = fact_[i - 1] * i % MOD;

        invfact_[N_] = pow_mod(fact_[N_], MOD - 2);
        for (int i = N_; i >= 1; --i) invfact_[i - 1] = invfact_[i] * i % MOD;
    }

    static long long pow_mod(long long base, long long exp) {
        base %= MOD;
        if (base < 0) base += MOD;
        long long res = 1;

        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }

        return res;
    }

    static long long inv_mod(long long num) {
        assert(num % MOD != 0);
        return pow_mod(num, MOD - 2);
    }

    long long C(int n, int k) const {
        if (k < 0 || k > n || n > N_) return 0;
        return fact_[n] * invfact_[k] % MOD * invfact_[n - k] % MOD;
    }

    long long C_big(long long n, long long k) const {
        if (k < 0 || k > n) return 0;

        long long m = std::min(k, n - k);
        if (m > N_) return -1;

        long long n0 = n % MOD;
        if (n0 < m) return 0;

        long long num = 1;
        for (long long i = 0; i < m; ++i)
            num = num * ((n0 - i) % MOD) % MOD;

        return num * invfact_[(int)m] % MOD;
    }

private:
    int N_;
    std::vector<long long> fact_, invfact_;
};