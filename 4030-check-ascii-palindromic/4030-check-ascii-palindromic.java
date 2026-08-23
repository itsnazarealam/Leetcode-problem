class Solution {
    public boolean isPalindromic(String s) {
        String output = "";
        for(int i=0; i<s.length(); i++){
            output += intToBin(s.charAt(i)-0);
        }
        int l=0, r=output.length()-1;
        while(l<=r){
            if(output.charAt(l) != output.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
    String intToBin(int num){
        String ans = "";
        for(int i=7; i>=0; i--){
            if((num & (1<<i)) != 0){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
        return ans;
    }
}