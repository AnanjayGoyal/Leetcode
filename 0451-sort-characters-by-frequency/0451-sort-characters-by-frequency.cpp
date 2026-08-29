class Solution {
public:
    // Sort by frequency: highest frequency first
    static bool compare(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        // Sorting the HashMap
        vector<pair<char, int>> v;

        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), compare);

        // Building answer
        string ans = "";

        for (auto it : v) {

            char ch = it.first;
            int frequency = it.second;

            for (int i = 0; i < frequency; i++) {
                ans += ch;
            }
        }
        return ans;
    }
};