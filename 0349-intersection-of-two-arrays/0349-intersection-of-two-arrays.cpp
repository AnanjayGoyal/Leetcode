class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> ans;

        for(int x : nums2) {

            if(st.find(x) != st.end()) {
                ans.push_back(x);
                // Remove that value from the hashset after uisng it
                st.erase(x);
            }
        }
        return ans;
    }
};