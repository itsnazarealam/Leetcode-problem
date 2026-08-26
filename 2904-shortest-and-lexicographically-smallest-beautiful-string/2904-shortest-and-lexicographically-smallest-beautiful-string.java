class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int i=0, j=0, count=0;
        String ans = "";

        while(j<s.length()){
            if(s.charAt(j)=='1')
                count++;
            
            while(count>k || (count==k && s.charAt(i)=='0')){
                if(s.charAt(i)=='1')
                    count--;
                i++;
            }
            if(count==k){
                String str = s.substring(i, j+1);
                if(ans.isEmpty() ||
                    str.length()<ans.length() ||
                    str.length()==ans.length() && str.compareTo(ans)< 0){
                    ans = str;
                }
            }            
            j++;
        }

        return ans;
    }
}