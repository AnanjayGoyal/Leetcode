// First cancel all the valid pairs i.e. all the (), then there will be some opening brackets left, we need to add exactly those many cloding brackets to make the parenthesis valid, so after canceling all the valid pairs just count the number of opening brackets left.
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for (char c : s){
            if (c == '('){
                st.push(c);
            }
            else { // c == ')'
                if (st.empty()){
                    st.push(c);
                }
                else if (st.top() == '(') {
                    st.pop();  // Remove the matching pair
                }
                else if (st.top() == ')'){
                    st.push(c);
                }
            }
        }
        return st.size();
    }
};