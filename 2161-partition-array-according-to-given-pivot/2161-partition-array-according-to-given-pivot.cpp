// Here we have to preserve the order so we cannot use DNF
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int read = 0;
        int write = 0;

        // Put elements smaller than pivot
        while (read < n) {
            if (nums[read] < pivot) {
                ans[write] = nums[read];
                write++;
            }
            read++;
        }
        // Put elements equal to pivot
        read = 0;
        while (read < n) {
            if (nums[read] == pivot) {
                ans[write] = nums[read];
                write++;
            }
            read++;
        }

        // Put elements greater than pivot
        read = 0;
        while (read < n) {
            if (nums[read] > pivot) {
                ans[write] = nums[read];
                write++;
            }
            read++;
        }
        return ans;
    }
};