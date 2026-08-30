class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int x : nums){
            mp[x]++;
        }

        vector<int> ans;

        for (auto it : mp){
            if (it.second == 1){
                auto it2 = mp.find(it.first-1);
                auto it3 = mp.find(it.first+1);

                if (it2 == mp.end() && it3 == mp.end()){
                    ans.push_back(it.first);
                }
            }
        }

        return ans;
        
    }
};