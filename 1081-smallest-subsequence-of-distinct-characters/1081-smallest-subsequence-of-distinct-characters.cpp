class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n=s.size();
        string result;

        vector<int> lastInd(26);
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            lastInd[ch-'a'] = i;
        }

        vector<bool> taken(26, false);    
        string s2 = "";
        for(int i=0; i<n; i++){

            char ch = s[i];
            int idx = ch - 'a';

            if(taken[idx] == true){
                continue;
            }
            while(result.size() >0 && result.back() > ch && lastInd[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx] = true;
        }
        

        return result;
    }
};