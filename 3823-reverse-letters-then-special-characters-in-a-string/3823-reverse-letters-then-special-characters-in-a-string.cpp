class Solution {
public:
    bool check(char ch){
        if(ch=='!' || ch=='@' || ch=='#' || ch=='$' || ch=='%'||ch=='^'||ch=='&' || ch=='*'||ch=='('||ch==')'){
            return true;
        }
        return false;
    }
    string reverseByType(string s) {
        
        int i=0, j=s.size()-1;
        while(i<j){
            if(check(s[i]) && check(s[j])){
                swap(s[i], s[j]);
                i++, j--;
            }
            else if(!check(s[i])){
                i++;
            }
            else if(!check(s[j])){
                j--;
            }
        }

        i=0, j=s.size()-1;
        while(i<j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!isalpha(s[i])){
                i++;
            }
            else if(!isalpha(s[j])){
                j--;
            }
        }
        return s;
    }
};