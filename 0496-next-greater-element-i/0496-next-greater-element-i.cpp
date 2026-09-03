class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Find NGE for every element of nums2
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {

                nge[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        // Map elements in num1 to their next greater value in num2
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = nge[i];
        }

        // Build complete answer
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};