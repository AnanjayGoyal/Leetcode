class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        // Store frequency of s
        for(char c : s) {
            mp[c]++;
        }

        // Match with t
        for(char c : t) {
            if(mp.find(c) == mp.end())
                return false;

            mp[c]--;
        }

        // Now, all the frequencies have matched, so hahsmap should be empty
        for(auto it : mp) {
            if(it.second != 0)
                return false;
        }
        return true;
    }
};