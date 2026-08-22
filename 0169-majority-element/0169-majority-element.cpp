class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0;
        int vote = 0;
        int right = 0;

        while (right < n) {

            if (nums[right] == candidate) {
                vote++;
            }
            else if (vote == 0) {
                candidate = nums[right];
                vote = 1;
            }
            else {
                vote--;
            }
            right++;
        }

        // Verification is NOT needed here because
        // the problem guarantees a majority element exists.
        return candidate;
    }
};