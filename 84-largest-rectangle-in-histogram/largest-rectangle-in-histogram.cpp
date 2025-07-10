class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); 
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
    }
};