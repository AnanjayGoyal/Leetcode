class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> mp;

        // Store frequency
        for(char c : s) {
            mp[c]++;
        }

        // Process
        for(int i = 0; i < s.size(); i++) {

            auto it = mp.find(s[i]);

            if(it != mp.end() && it->second == 1) {
                return i;
            }
        }

        return -1;
        
    }
};