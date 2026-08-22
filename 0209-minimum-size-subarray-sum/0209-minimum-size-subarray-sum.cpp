// Here only positive integers are used so we can directly use variable sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int mini = INT_MAX;

        while (right < n) {

            sum += nums[right];

            while (sum >= target) {
                
                // Process answer
                mini = min(mini, right - left + 1);

                // Remove left element
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (mini == INT_MAX)
            return 0;

        return mini;
    }
};