class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        // Split s into words
        stringstream ss(s);

        while(ss >> word) {
            words.push_back(word);
        }

        // Number of characters and words must match
        if(pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp1;  // a → dog, b → cat
        unordered_map<string, char> mp2;  // dog → a, cat → b

        for(int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string w = words[i];

            auto it1 = mp1.find(ch);  // pattern to word

            if(it1 != mp1.end()) {
                if(it1->second != w)
                    return false;
            }

            auto it2 = mp2.find(w);  // word to pattern

            if(it2 != mp2.end()) {
                if(it2->second != ch)
                    return false;
            }
            // Store both mappings
            mp1[ch] = w;
            mp2[w] = ch;
        }
        return true;
    }
};