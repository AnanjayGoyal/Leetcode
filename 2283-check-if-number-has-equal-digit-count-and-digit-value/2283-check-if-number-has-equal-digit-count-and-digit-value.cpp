// The digit at ith index should repeat i times.
class Solution {
public:
    bool digitCount(string num) {

        unordered_map<int, int> mp;

        // Count each digit
        for (char ch : num) {
            mp[ch - '0']++;
        }

        // Check digit count
        for (int i = 0; i < num.size(); i++) {

            int digit = num[i] - '0';

            if (mp[i] != digit) {
                return false;
            }
        }

        return true;
    }
};