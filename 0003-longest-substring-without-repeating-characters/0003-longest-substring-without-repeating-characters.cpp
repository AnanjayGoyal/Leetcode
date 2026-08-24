// Sliding Window + HashMap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int right = 0;
        int ans = 0;

        while(right < s.size()) {

            // Add current character
            mp[s[right]]++;

            // Window is invalid if duplicate exists
            while(mp[s[right]] > 1) {

                // Remove left character
                mp[s[left]]--;

                if(mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }

            // Window is valid → update answer
            ans = max(ans, right - left + 1);

            // Expand
            right++;
        }
        return ans;
    }
};