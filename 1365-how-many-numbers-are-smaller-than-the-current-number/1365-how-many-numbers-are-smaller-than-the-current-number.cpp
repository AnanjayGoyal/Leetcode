// While iterating, we need to remember the element, so we use hahsmaps.
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        unordered_map<int, int> mp;

        // Count frequency
        for (int x : nums) {
            mp[x]++;
        }

        // Put numbers into vector
        vector<int> v;

        for (auto it : mp) {
            v.push_back(it.first);
        }

        // Sort numbers
        sort(v.begin(), v.end());

        // Store answer for each number
        unordered_map<int, int> smaller;

        int count = 0;

        for (int x : v) {

            smaller[x] = count;

            count += mp[x];
        }

        // Build final answer
        vector<int> ans;

        for (int x : nums) {
            ans.push_back(smaller[x]);
        }

        return ans;
    }
};