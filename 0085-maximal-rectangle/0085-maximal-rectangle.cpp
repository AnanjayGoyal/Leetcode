class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n, -1);
        vector<int> nse(n, n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pse[i] = st.top();
            }

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }

        // Calculate maximum area
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int ans = 0;

        for (int i = 0; i < rows; i++) {

            // Build histogram
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }

            // Largest Rectangle for this row
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};