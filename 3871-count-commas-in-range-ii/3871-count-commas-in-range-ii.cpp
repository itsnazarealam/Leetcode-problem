class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        if (n >= 1000) {
            long long count = min(n, 999999LL) - 1000 + 1;
            ans += count;
        }

        if (n >= 1000000) {
            long long count = min(n, 999999999LL) - 1000000 + 1;
            ans += count * 2;
        }

        if (n >= 1000000000LL) {
            long long count = min(n, 999999999999LL) - 1000000000LL + 1;
            ans += count * 3;
        }

        if (n >= 1000000000000LL) {
            long long count = min(n, 999999999999999LL) - 1000000000000LL + 1;
            ans += count * 4;
        }

        if (n >= 1000000000000000LL) {
            long long count = n - 1000000000000000LL + 1;
            ans += count * 5;
        }

        return ans;
    }
};