class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int n = nums.size();

        int read = 0;
        int write = 1;

        while (read < n && write < n) {

            // Find odd number at even index
            while (read < n && nums[read] % 2 == 0)
                read += 2;

            // Find even number at odd index
            while (write < n && nums[write] % 2 != 0)
                write += 2;

            // Swap wrong elements
            if (read < n && write < n)
                swap(nums[read], nums[write]);
        }

        return nums;
    }
};