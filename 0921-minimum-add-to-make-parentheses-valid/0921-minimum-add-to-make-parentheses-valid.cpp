// Remove every valid () pair.
// Whatever parentheses are left are unmatched,
// and each unmatched parenthesis requires exactly one insertion to match it.
//
// Here only circular parentheses are present: '(' and ')'.

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for (char ch : s) {

            if (ch == '(') {
                st.push(ch);
            }
            else { // ')'

                // If there is an opening '(' available,
                // match it and remove the pair.
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }

                // No '(' available → this ')' is unmatched.
                // Keep it because we will need to insert '(' for it.
                else {
                    st.push(ch);
                }
            }
        }

        // Whatever remains is unmatched.
        // Each one requires exactly one insertion.
        return st.size();
    }
};