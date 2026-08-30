// search and store problem in hashmap
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {

        unordered_map<int, int> mp;

        int pairs = 0;

        for (int x : nums) {

            // Search
            if (mp[x] == 1) {
                pairs++;
                mp[x] = 0;
            }
            else {
                // Store
                mp[x] = 1;
            }
        }

        int leftovers = 0;

        for (auto it : mp) {
            leftovers += it.second;
        }

        return {pairs, leftovers};
    }
};