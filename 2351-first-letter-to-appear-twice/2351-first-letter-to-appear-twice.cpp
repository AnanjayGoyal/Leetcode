class Solution {
public:
    char repeatedCharacter(string s) {

        unordered_set<char> st;

        for (char ch : s) {

            // Search
            if (st.find(ch) != st.end()) {
                return ch;
            }

            // Store
            st.insert(ch);
        }

        return ' ';
    }
};