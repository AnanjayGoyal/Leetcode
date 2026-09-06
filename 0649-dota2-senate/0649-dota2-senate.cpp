// Exaple : RDD --> (iteration 1) R bans D --> (iteration 2) D is banned so skip it --> (iteration 3) Another D bans R (It works in Circular) --> FInally Only rightmost D is left.
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int n = senate.size();
        // Store positions
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            }
            else {
                dire.push(i);
            }
        }
        // Continue until one party is eliminated
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            radiant.pop();
            int d = dire.front();
            dire.pop();
            // Whoever comes first gets to ban the other
            if (r < d) {
                radiant.push(r + n);
            }
            else {
                dire.push(d + n);
            }
        }
        if (radiant.empty()) {
            return "Dire";
        }
        return "Radiant";
    }
};