// Seach and Store HashMap Problem.
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        unordered_map<int, int> mp;

        long long goodPairs = 0;

        for (int i = 0; i < nums.size(); i++) {

            int key = nums[i] - i;

            // Value is the number of new pairs formed by the current element, not total pairs formed by that key.
            goodPairs += mp[key];

            mp[key]++;
        }

        // Total number of pairs
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;

        // Bad pairs = Total pairs - Good pairs
        return totalPairs - goodPairs;
    }
};