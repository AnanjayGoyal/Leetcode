// Here we want to mentain the order, so we cannot use alternate pointers approach.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int read = 0;
        int writePos = 0;
        int writeNeg = 1;

        while (read < n) {

            if (nums[read] > 0) {
                ans[writePos] = nums[read];
                writePos += 2;
            }
            else {
                ans[writeNeg] = nums[read];
                writeNeg += 2;
            }

            read++;
        }

        return ans;
    }
};