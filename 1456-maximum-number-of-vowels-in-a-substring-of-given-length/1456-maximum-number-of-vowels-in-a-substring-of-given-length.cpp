class Solution {
public:
    int maxVowels(string s, int k) {

        int left = 0;
        int right = 0;
        int vowels = 0;
        int maxi = 0;

        while (right < s.length()) {

            if (s[right] == 'a' || s[right] == 'e' ||
                s[right] == 'i' || s[right] == 'o' ||
                s[right] == 'u') {
                vowels++;
            }

            if (right - left + 1 == k) {
                maxi = max(maxi, vowels);

                if (s[left] == 'a' || s[left] == 'e' ||
                    s[left] == 'i' || s[left] == 'o' ||
                    s[left] == 'u') {
                    vowels--;
                }
                left++;
            }
            right++;
        }
        return maxi;
    }
};