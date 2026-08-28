class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        for (char c : s){
            mp[c]++;
        }

        for (char d : t){

            auto it = mp.find(d);

            if (it != mp.end() && it->second != 0){
                it->second --;
            }
            else {
                return false;
            }
        }
        return true;
    }
};