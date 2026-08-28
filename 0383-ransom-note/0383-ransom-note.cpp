class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mp;

        // Store frequency of magazine
        for(char c : magazine) {
            mp[c]++;
        }

        // Build ransomNote from the letters of magazine
        for(char c : ransomNote) {

            auto it = mp.find(c);

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