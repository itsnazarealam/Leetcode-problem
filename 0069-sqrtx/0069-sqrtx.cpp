class Solution {
public:
    int mySqrt(int x) {
        long long ans=0, i=0;
        while(i<=x){
            if(i*i <= x)
                ans = i;
            else
                break;
            i++;
        }
        return ans;
    }
};