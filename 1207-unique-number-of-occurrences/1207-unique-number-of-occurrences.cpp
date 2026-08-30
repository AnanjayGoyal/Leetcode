// count the occurances in the hashmap
// store the occurances in hashset to check any duplicates
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> mp;
        unordered_set<int> st;

        // Count frequency of each number
        for (int x : arr) {
            mp[x]++;
        }

        // Store frequencies in HashSet
        for (auto it : mp) {

            auto it2 = st.find(it.second);

            // If frequency already exists
            if (it2 != st.end()) {
                return false;
            }

            st.insert(it.second);
        }
        return true;
    }
};