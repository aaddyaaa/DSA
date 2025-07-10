class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        // Build the histogram
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
    }
};