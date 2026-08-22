class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        while (right < n) {

            // Include current character
            mp[s[right]]++;

            // Window contains a, b, c
            while (mp['a'] > 0 &&
                   mp['b'] > 0 &&
                   mp['c'] > 0) {

                // Process
                ans += n - right;

                // Remove left character
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};