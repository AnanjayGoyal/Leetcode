// Repeatedly find Maximum (most) frequent character so use heaps
class Solution {
public:
    string frequencySort(string s) {
        // Count frequency
        unordered_map<char, int> freq;
        for (char ch : s)
            freq[ch]++;

        // Max Heap, {frequency, character}
        priority_queue<pair<int, char>> pq;

        // Put {frequency, character} into heap
        for (auto [ch, count] : freq)
            pq.push({count, ch});

        string ans;
        while (!pq.empty()) {

            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            while (count--)
                ans += ch;
        }
        return ans;
    }
};