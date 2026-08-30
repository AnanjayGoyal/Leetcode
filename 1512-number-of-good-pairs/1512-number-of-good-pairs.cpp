// This is a search and store hashmap problem.
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int, int> mp;
        int ans = 0;
        for (int x : nums) {

            // All previous x's form a pair with current x
            ans += mp[x];

            // Store current x
            mp[x]++;
        }
        return ans;
    }
};