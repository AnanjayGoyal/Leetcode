class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        vector<int> ans;

        // Frequency of characters in p
        for(char c : p) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        
        while(right < s.size()) {
            // Add current character
            window[s[right]]++;

            // Window size should not exceed p's size
            while(right - left + 1 > p.size()) {
                window[s[left]]--;

                if(window[s[left]] == 0) {
                    window.erase(s[left]);
                }
                left++;
            }
            // Window has exactly p's size
            if(right - left + 1 == p.size()) {
                if(window == need) {
                    ans.push_back(left);
                }
            }
            right++;
        }
        return ans;
    }
};