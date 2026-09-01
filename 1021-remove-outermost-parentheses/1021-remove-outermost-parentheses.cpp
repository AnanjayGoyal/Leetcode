// This can be done by the Stacks, but we have to return this as a string so we can also do this without stacks, just mentain depth, when the depth is more than 1 that means we have entered the inner parenthsis, create answer.

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for (char c : s) {

            if (c == '(') {
                depth++;

                if (depth > 1) {
                    ans += c;
                }
            }
            else { // ')'
                depth--;

                if (depth > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};