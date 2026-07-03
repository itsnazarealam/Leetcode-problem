class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int >mp;
        for(auto x : t)
            mp[x]++;

        int i=0, j=0, count=0;
        int minLen=INT_MAX, lastInd=-1;
        while(j<s.size()){
            if(mp[s[j]] > 0)
                count++;
            mp[s[j]]--;

            while(count==t.size()){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    lastInd = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0)
                    count--;
                
                i++;
            }
            j++;
        }
        return lastInd==-1?"":s.substr(lastInd, minLen);
    }
};