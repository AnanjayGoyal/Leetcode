 // When we removed k cards from front or end of the array, we will be left with a contiguous subarray of elements, to return the maximum score, the leftover subarray sum should be minimum. So, Answer = Total Sum - Minimum Window Sum.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        for (int x : cardPoints)
            total += x;

        int windowSize = n - k;

        if (windowSize == 0)
            return total;

        int left = 0;
        int right = 0;
        int sum = 0;
        int mini = INT_MAX;

        while (right < n) {
            sum += cardPoints[right];

            if (right - left + 1 == windowSize) {
                mini = min(mini, sum);
                sum -= cardPoints[left];
                left++;
            }
            right++;
        }
        return total - mini;
    }
};