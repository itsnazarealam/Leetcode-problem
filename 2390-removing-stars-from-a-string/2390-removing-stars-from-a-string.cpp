class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*' && i>=0){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string s2 = "";
        while(!st.empty()){
            s2 += st.top();
            st.pop();
        }
        reverse(s2.begin(), s2.end());
        return s2;
    }
};