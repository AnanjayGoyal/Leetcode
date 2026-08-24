class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // prefix sum 0 exists once
        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for(int x : nums) {

            prefix += x;
            int need = prefix - k;

            // Search previous prefix sum
            auto it = mp.find(need);

            if(it != mp.end()) {
                ans += it->second;
            }
            // Store current prefix sum
            mp[prefix]++;
        }
        return ans;
    }
};