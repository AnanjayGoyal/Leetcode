// We need to remember the current number while itearating all the numbers to check which are smaller, so we will use hashmaps. hashmap will store "number:smaller_numbers" as key:value pairs.
// sort the vector then insert it into the hashmap, the index of each element in the sorted vetor is the smaller_numbers for that number, so store number:index in hahsmap
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;

        // Sort
        sort(v.begin(), v.end());

        // Store first index of every number
        unordered_map<int, int> mp;

        for (int i = 0; i < v.size(); i++) {

            if (mp.find(v[i]) == mp.end()) {
                mp[v[i]] = i;
            }
        }

        // Build answer
        vector<int> ans;

        for (int x : nums) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};