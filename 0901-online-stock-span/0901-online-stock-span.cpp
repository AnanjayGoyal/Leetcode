// Track distance of Prev greater element
class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;

    StockSpanner() {
    }
    int next(int price) {
        int i = prices.size();
        prices.push_back(price);

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int ans;

        if (!st.empty()) {
            ans = i - st.top();
        }
        else {
            // Stack is empty so no prev greater element exists so count all
            ans = i + 1;
        }
        st.push(i);
        return ans;
    }
};