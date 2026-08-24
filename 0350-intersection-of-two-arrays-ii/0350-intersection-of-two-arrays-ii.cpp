class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> freq;

        // Store frequencies of nums1
        for(int x : nums1) {
            freq[x]++;
        }

        vector<int> ans;

        // Check nums2
        for(int x : nums2) {
            auto it = freq.find(x);

            if(it != freq.end() && it->second > 0) {

                ans.push_back(x);
                it->second--;
            }
        }
        return ans;
    }
};