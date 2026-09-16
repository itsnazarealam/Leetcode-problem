class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even=0, odd=0;
        for(int i=1; i<=2*n; i++){
            if(i%2==0)
                even += i;
            else
                odd += i;
        }
        return gcd(even, odd);
    }
};