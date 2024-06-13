class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temp) {
        std::stack<int> st;
        std::vector<int> res(temp.size(), 0);
        
        for (int i = temp.size() - 1; i >= 0; i--) {
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : (st.top() - i);
            st.push(i);
        }
        
        return res;
    }
};