class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans,height * width);
            }
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            ans = max(ans,height * width);
        }

        return ans;
    }
};