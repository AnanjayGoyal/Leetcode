// kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        int right = 1;

        while (right < n) {

            if (currSum + nums[right] > nums[right]) {
                currSum += nums[right];
            }
            else {
                currSum = nums[right];
            }
            
            if (currSum > maxSum) {
                maxSum = currSum;
            }
            right++;
        }
        return maxSum;
    }
};