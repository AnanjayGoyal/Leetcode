class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(), deck.end());
        queue<int> q;

        // Store positions
        for (int i = 0; i < deck.size(); i++)
            q.push(i);

        vector<int> ans(deck.size());

        for (int x : deck) {

            // Process front position
            int pos = q.front();
            q.pop();

            // Put card there
            ans[pos] = x;

            // Send next position to back
            if (!q.empty()) {
                int next = q.front();
                q.pop();
                q.push(next);
            }
        }
        return ans;
    }
};