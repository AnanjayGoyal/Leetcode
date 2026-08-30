class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> mp;

        // Store the frequencies 
        for (int x : arr){
            mp[x]++;
        }

        // For largest, we can sort the hashmap but we only need 1 largest so better to use a single maximum (ans) variable.

        int ans = -1;

        for (auto y : mp){
            if (y.first == y.second){
                if (y.first > ans){
                    ans = y.first;
                }
            }
        }
        return ans;
        
    }
};