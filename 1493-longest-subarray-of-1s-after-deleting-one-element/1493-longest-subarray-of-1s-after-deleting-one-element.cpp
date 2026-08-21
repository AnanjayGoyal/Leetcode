class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeros = 0;
        int maxLen = 0;

        while (right < n) {
            // Process the current element
            if (nums[right] == 0) {
                zeros++;
            }

            // Subarray is invalid → shrink window
            while (zeros > 1) {

                if (nums[left] == 0) {   // Remove the left element
                    zeros--;
                }
                left++;
            }

            // Process answer
            maxLen = max(maxLen, right - left);
            right++;
        }
        return maxLen;
    }
};