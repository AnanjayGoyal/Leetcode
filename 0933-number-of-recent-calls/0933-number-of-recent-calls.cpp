class RecentCounter {
public:
    queue<int> q;

    RecentCounter() { 
    }
    
    int ping(int t) {
        // Add current call
        q.push(t);

        // Remove calls older than t - 3000
        while (q.front() < t - 3000) {
            q.pop();
        }

        // Remaining calls are recent
        return q.size();
    }
};