class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int odd = 0;
        int count = 0;

        while (right < nums.size()) {

            // Include current element
            if (nums[right] % 2 == 1)
                odd++;

            // Invalid
            while (odd > k) {
                if (nums[left] % 2 == 1)
                    odd--;

                left++;
            }
            // Process
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};