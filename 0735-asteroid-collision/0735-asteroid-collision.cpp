class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int curr : asteroids) {
            bool alive = true;

            // Checking if the Collision is Possible.
            while (alive && !st.empty() && st.top() > 0 && curr < 0) {
                // Stack top is smaller
                if (st.top() < -curr) {
                    st.pop();
                }
                // Both are same size
                else if (st.top() == -curr) {
                    st.pop();
                    alive = false;
                }
                // Current is smaller
                else {
                    alive = false;
                }
            }
            // Current asteroid survived
            if (alive) {
                st.push(curr);
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};