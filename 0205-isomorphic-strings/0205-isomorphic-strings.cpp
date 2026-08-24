class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.size(); i++) {

            char a = s[i];
            char b = t[i];

            // s -> t
            auto it1 = mp1.find(a);

            if(it1 != mp1.end()) {      // Check if s exists in the map
                if(it1->second != b)    // Check if s is mapped to t in map
                    return false;
            }

            // t -> s
            auto it2 = mp2.find(b);

            if(it2 != mp2.end()) {
                if(it2->second != a)
                    return false;
            }

            // Store mappings
            mp1[a] = b;
            mp2[b] = a;
        }
        return true;
    }
};