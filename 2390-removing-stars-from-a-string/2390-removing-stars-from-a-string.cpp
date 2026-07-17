class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string s2 = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*' && i>=0){
                s2.pop_back();
            }
            else{
                s2 += s[i];
            }
        }
        cout<<s2;
        return s2;
    }
};