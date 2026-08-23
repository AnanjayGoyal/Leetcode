class KthLargest {
public:

    // Used in both Constructor, add function
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    // Build Min Heap containing the K largest numbers
    KthLargest(int k, vector<int>& nums) {
        K = k;

        for (int x : nums) {
            pq.push(x);

            if (pq.size() > K)
                pq.pop();
        }
    }
    // Add new number and return current Kth largest
    int add(int val) {
        pq.push(val);
        
        if (pq.size() > K)
            pq.pop();

        return pq.top();
    }
};