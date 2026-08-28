// For a string to form a palindrome, characters on the left and right sides must occur in matching pairs. Therefore, every character must occur an even number of times, except for at most one character, which may occur an odd number of times and can be placed in the center of the palindrome.

// Empty String is itself a Palindorme

class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> mp;

        for (char c : s){
            mp[c]++;
        }

        int oddkey = 0; // 1 oddkey can be there.
        int length = 0;

        for (auto& [key, freq] : mp){

            if (freq % 2 != 0){
                oddkey++;
            }

            // Take only the paired characters
            length += (freq / 2) * 2;
        }

        // One odd character can be placed in the center
        if (oddkey > 0){
            length++;
        }

        return length;
    }
};