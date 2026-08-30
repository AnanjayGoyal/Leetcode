class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums){
            if (x%2 == 0){
                mp[x]++;
            }
        }

        // sort the hashmap from low to high for keys and high to low for values.
        // Here better approach is instead of using sorting, simply mentain 2 variables.

        int ans = -1;
        int maxFreq = 0;
        for (auto it : mp) {

            int number = it.first;
            int frequency = it.second;

            if (frequency > maxFreq) {
                maxFreq = frequency;
                ans = number;
            }
            else if (frequency == maxFreq) {
                ans = min(ans, number);
            }
        }

        return ans;
    }
};