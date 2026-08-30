// This is a search and store hashmap problem 
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int ans = 0;

        for (int x : nums) {

            // Search
            ans += mp[x - k];
            ans += mp[x + k];

            // Store
            mp[x]++;
        }

        return ans;
    }
};