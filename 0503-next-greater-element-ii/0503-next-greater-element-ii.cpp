class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse array twice
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            while (!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            // Only store indices from the first traversal
            if (i < n) {
                st.push(idx);
            }
        }
        return ans;
    }
};