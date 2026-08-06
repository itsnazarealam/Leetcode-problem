class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(n != 0){
            int temp = n;
            int mul = 1;
            while(temp>0){
                mul *= temp%10;
                temp /= 10;
            }
            if(mul%t==0)
                return n;
            else
                n++;
        }
        return 0;
    }
};