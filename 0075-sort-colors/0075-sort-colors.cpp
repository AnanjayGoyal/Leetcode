class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0;       // keeps track of 0s
        int mid = 0;       // current element / keeps track of 1s
        int high = n - 1;  // keeps track of 2s

        while (mid <= high) {

            if (nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            else if (nums[mid] == 1) {

                mid++;
            }

            else { // nums[mid] == 2

                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};