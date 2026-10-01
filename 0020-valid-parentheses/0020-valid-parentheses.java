class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> st = new Stack<>();
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else{
                if(!st.empty()){
                    if((ch==')' && st.peek()=='(') || 
                        (ch=='}' && st.peek()=='{') || 
                        (ch==']' && st.peek()=='[')){
                        st.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
}