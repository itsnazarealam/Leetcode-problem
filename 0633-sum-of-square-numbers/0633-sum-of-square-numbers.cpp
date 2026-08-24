class Solution {
public:
    int m = 1e9+7;
    bool judgeSquareSum(int c) {  
        
        long long j = sqrt(c);
        long long i=0;
        
        while(i<=j){
            long long mul = (i*i + j*j);
            if(mul== c)
                return true;
            if(mul < c)
                i++;
            else
                j--;
        }
        return false;
    }
};