class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        int left = 0;
        int right = 0;

        int sum = 0;
        int maxi = INT_MIN;

        while (right < n) {

            sum += nums[right];

            if (right - left + 1 == k) {

                maxi = max(maxi, sum);

                sum -= nums[left];
                left++;
            }

            right++;
        }

        return (double)maxi / k;
    }
};