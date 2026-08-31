// Given : 4 <= nums.length <= 50 
// Nested for loops : O(n⁴)	and O(1) for Time and Space  --> Do this bcs marked easy
// HashMap: O(n³) and O(n²) for Time and Space
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {

        int ans = 0;

        for (int a = 0; a < nums.size(); a++) {
            for (int b = a + 1; b < nums.size(); b++) {
                for (int c = b + 1; c < nums.size(); c++) {
                    for (int d = c + 1; d < nums.size(); d++) {

                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};