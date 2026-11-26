class Solution {
public:
    bool canAliceWin(int n) {
        int a=10;
        int step=0;
        while(n>0){
            if(n-a < 0){
                break;
            }
            n -= a;
            a--;
            step++;
        }
        return step%2==1;
    }
};