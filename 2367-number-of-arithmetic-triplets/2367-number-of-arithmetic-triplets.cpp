// search and store hashmap problem 

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {

        unordered_map<int, int> mp;

        int ans = 0;

        for (int x : nums) {

            // Search
            if (mp.find(x - diff) != mp.end() &&
                mp.find(x - 2 * diff) != mp.end()) {
                
                ans++;
            }

            // Store
            mp[x] = 1;
        }

        return ans;
    }
};