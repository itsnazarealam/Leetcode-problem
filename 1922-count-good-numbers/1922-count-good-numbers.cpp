class Solution {
public:
    int mod = 1e9+7;
    int pow(long long a, long long b){
        if(b==0)
            return 1;

        long long half = pow(a, b/2);
        long long result = (half*half)%mod;
        if(b%2==1)
            result = (result*a)%mod;

        return result;
    }
    int countGoodNumbers(long long n) {

        long long odd = pow(5, (n+1)/2);
        long long even = pow(4, n/2);

        return (long long)(odd * even)%mod;
    }
};