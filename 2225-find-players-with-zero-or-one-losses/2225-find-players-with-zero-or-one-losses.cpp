class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> noLoss;     // players who have never lost
        unordered_map<int, int> losses; // players who lost, with number of losses

        // Put every player into the set initially
        for (auto match : matches) {
            noLoss.insert(match[0]);
            noLoss.insert(match[1]);
        }

        // Remove losers from noLoss
        for (auto match : matches) {

            int loser = match[1];

            noLoss.erase(loser);
            losses[loser]++;
        }
        vector<int> zeroLoss;
        vector<int> oneLoss;

        for (auto player : noLoss) {
            zeroLoss.push_back(player);
        }

        for (auto it : losses) {
            if (it.second == 1) {
                oneLoss.push_back(it.first);
            }
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());
        return {zeroLoss, oneLoss};
    }
};