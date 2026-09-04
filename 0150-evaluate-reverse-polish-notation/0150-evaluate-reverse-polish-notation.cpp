class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string curr : tokens) {
            // Number
            if (curr != "+" && curr != "-" &&
                curr != "*" && curr != "/") {
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