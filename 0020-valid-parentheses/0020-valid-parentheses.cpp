class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') { // Opening Brackets
                st.push(ch);
            }
            else {  // Closing brackets
                // We are matching closing brackets with the opening brackets, first the stack should not be empty.
                if (st.empty()) {
                    return false;
                }
                // Correct matching pair, then pop
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {

                    st.pop();
                }
                // Closing bracket does not match
                else {
                    return false;
                }
            }
        }
        // If all the parenthesis are matched, then the stack should become empty.
        return st.empty();
    }
};