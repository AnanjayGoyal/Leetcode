// [2, 3, +, 4, *] --> push 2 --> push 3 --> + appears so add and remove 2, 3 from stacks and push 6 to stack --> push 4, now stack contains [6, 4] --> * appears so push 24 to stack ---> Final result is 24.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string curr : tokens) {
            // Number
            if (curr != "+" && curr != "-" && curr != "*" && curr != "/") {
                st.push(stoi(curr));
            }
            // Operator
            else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result;
                
                if (curr == "+")
                    result = a + b;
                else if (curr == "-")
                    result = a - b;
                else if (curr == "*")
                    result = a * b;
                else
                    result = a / b;

                st.push(result);
            }
        }
        return st.top();
    }
};