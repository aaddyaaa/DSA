class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if (arr[i]>0) st.push(arr[i]); //positive
            else {
                while(!st.empty()&& st.top()>0 && st.top()<abs(arr[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(arr[i])){
                    st.pop();
                }
                else if (st.empty()||st.top()<0){
                    st.push(arr[i]);
                }
            }
        }
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }
    return result;
    }
};