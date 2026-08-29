// For Frequent elements, we will use HashMaps.
// For Top k elements, we use min Heap.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        // Min Heap
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        for (auto it : freq) {
            // We have to minimise the frequency (Push it.second)
            pq.push({it.second, it.first});    

            // Keeping top k elements in the heap
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};