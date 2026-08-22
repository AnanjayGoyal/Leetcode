// We need 2 candidates, as array can have at most 2 elements occurring > n/3 times.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0;
        int candidate2 = 0;
        int vote1 = 0;
        int vote2 = 0;
        int right = 0;
        // Find candidates
        while (right < n) {
            if (nums[right] == candidate1) {
                vote1++;
            }
            else if (nums[right] == candidate2) {
                vote2++;
            }
            else if (vote1 == 0) {
                candidate1 = nums[right];
                vote1 = 1;
            }
            else if (vote2 == 0) {
                candidate2 = nums[right];
                vote2 = 1;
            }
            else {
                vote1--;
                vote2--;
            }
            right++;
        }
        // Verification
        int freq1 = 0;
        int freq2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1)
                freq1++;
            else if (nums[i] == candidate2)
                freq2++;
        }
        vector<int> ans;
        if (freq1 > n / 3)
            ans.push_back(candidate1);
        if (freq2 > n / 3)
            ans.push_back(candidate2);
        return ans;
    }
};