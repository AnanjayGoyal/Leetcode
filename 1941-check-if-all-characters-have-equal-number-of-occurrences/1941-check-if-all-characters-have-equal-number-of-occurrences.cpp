class Solution {
public:
    bool areOccurrencesEqual(string s) {

        unordered_map<char, int> mp;

        for (char ch : s){
            mp[ch]++;
        }
        int occurances = mp[s[0]];

        for (auto it : mp){
            if (it.second != occurances){
                return false;
            }
        }
        return true;
        
    }
};