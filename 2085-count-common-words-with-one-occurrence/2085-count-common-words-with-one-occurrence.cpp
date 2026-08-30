class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {

        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;

        // Count words in words1
        for (string word : words1) {
            mp1[word]++;
        }

        // Count words in words2
        for (string word : words2) {
            mp2[word]++;
        }

        int ans = 0;

        // Check words from any map and match it with other
        for (auto it : mp1) {

            string word = it.first;

            // Word must occur exactly once in both
            if (it.second == 1 && mp2[word] == 1) {
                ans++;
            }
        }
        return ans;
    }
};