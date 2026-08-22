class Solution {
    public boolean checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int mul = 1;
        while(n>0){
            int digit = n%10;
            sum += digit;
            mul *= digit;
            n /= 10;
        }
        return temp%(sum+mul)==0;
    }
}