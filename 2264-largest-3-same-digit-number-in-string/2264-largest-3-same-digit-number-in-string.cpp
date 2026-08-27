class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        int i=0, j=1;
        while(j<n){
            if(num[i]==num[j]){
                if(j-i+1==3){
                    if(ans < num.substr(i,3)){
                        ans = num.substr(i,3);
                    }
                }
                j++;
            }
            else{
                i++;
                j = i+1;
            }
        } 
        return ans;
    }
};