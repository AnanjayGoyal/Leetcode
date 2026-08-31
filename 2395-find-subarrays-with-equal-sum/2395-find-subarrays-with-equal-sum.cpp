// for Subarray with equal sum, we need to process the Subarray (Sliding Window) also we need to remember the sum of the previous subarray (HashMaps).
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {

        int n = nums.size();
        int left = 0, right = 0;
        unordered_set<int> sums;

        while (right < n) {

            // Window formed
            if (right - left + 1 == 2) {

                int sum = nums[left] + nums[right];

                if (sums.find(sum) != sums.end()) {  // Search 
                    return true;
                }

                sums.insert(sum);    // Store

                left++;
            }

            right++;
        }

        return false;
    }
};