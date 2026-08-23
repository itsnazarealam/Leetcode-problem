class Solution {
public:
    string intToBin(int num){
        string ans = "";
        for(int i=7; i>=0; i--){
            if(num & (1<<i)){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
        return ans;
    }
    bool isPalindromic(string s) {
        string output = "";
        for(int i=0; i<s.size(); i++){
            output += intToBin(s[i]-0);
        }
        int l=0, r=output.size()-1;
        while(l<=r){
            if(output[l] != output[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};