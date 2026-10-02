class Solution {
public:
    void solve(vector<int>& arr, int index, vector<int>& current,
               vector<vector<int>>& ans) {

        if (index < 0) {
            ans.push_back(current);
            return;
        }

        // Take
        current.push_back(arr[index]);
        solve(arr, index - 1, current, ans);
        current.pop_back();

        // Dont take
        solve(arr, index - 1, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(arr, arr.size() - 1, current, ans);
        return ans;
    }
};