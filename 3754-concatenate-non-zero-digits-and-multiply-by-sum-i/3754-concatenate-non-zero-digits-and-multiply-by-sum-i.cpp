class Solution {
public:
    long long sumAndMultiply(int n) {
        
        if(n==0)    return 0;    
        string s="";
        long long sum = 0;
        while(n>0){
            int digit = n%10;
            sum += digit;
            if(digit != 0)
                s += (digit+'0');
            n /= 10;
        }
        reverse(begin(s), end(s));
        int num = stoi(s);

        return (long long)(num*sum);
    }
};