class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (char curr : s) {
            bool currIsRemoved = false;

            // This while loop runs one time for each for loop elment, so we can also use just a if statement here, instead of the while loop
            while (!st.empty() && st.top() == curr) {
                st.pop();
                currIsRemoved = true;
                break;
            }

            if (!currIsRemoved) {
                st.push(curr);
            }
        }

        string ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};