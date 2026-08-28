class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
            unordered_set<char> st;
            int count = 0;

            for (char ch : jewels){
                st.insert(ch);
            }

            for (char c : stones){
                auto it = st.find(c);

                if (it != st.end()){
                    count++;
                }
            } 
            return count;       
    }
};