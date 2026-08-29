// Convert the paragraph into lowercase words, Ignore punctuation and extract words.
// Put banned words into a HashSet, to avoid checking the entire banned array again while checking the final hashmap for most frequent word.
// Find the non banned word with the highest frequency.
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> ban;
        for (string word : banned) {  // Banned words
            ban.insert(word);
        }
        // Extracting the words
        for (char& ch : paragraph) {  // Convert paragraph to lowercase
            ch = tolower(ch);
        }
        string word = "";
        for (int i = 0; i <= paragraph.size(); i++) {
            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word += paragraph[i];
            }
            else {
                if (word != "") {
                    // Count only if word is not banned
                    if (ban.find(word) == ban.end()) {
                        mp[word]++;
                    }
                    word = "";
                }
            }
        }
        // Find word with maximum frequency
        string ans = "";
        int maxFreq = 0;
        for (auto it : mp) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};