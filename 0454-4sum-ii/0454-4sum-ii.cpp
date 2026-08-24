class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> mp;

        // Store frequencies of nums1 + nums2
        for(int a : nums1) {
            for(int b : nums2) {
                mp[a + b]++;
            }
        }

        int ans = 0;

        // Search using nums3 + nums4
        for(int c : nums3) {
            for(int d : nums4) {

                int need = -(c + d);

                auto it = mp.find(need);

                if(it != mp.end()) {
                    ans += it->second;
                }
            }
        }

        return ans;
    }
};