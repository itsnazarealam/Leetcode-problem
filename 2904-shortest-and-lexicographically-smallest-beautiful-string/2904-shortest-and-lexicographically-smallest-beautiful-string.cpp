class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int i=0, j=0, count=0;
        string ans = "";

        while(j<s.size()){
            if(s[j]=='1')
                count++;
            
            while(count>k || (count==k && s[i]=='0')){
                if(s[i]=='1')
                    count--;
                i++;
            }
            if(count==k){
                string str = s.substr(i, j-i+1);
                if(ans.empty() ||
                    str.length()<ans.length() ||
                    str.length()==ans.length() && str<ans){
                    ans = str;
                }
            }            
            j++;
        }

        return ans;
    }
};