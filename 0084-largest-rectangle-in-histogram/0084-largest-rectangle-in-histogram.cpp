class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ind = st.top();
                int nse = i;
                st.pop();
                int pse = st.empty() ? -1: st.top();
                ans = max(ans,heights[ind]*(i-pse-1));

            }
            st.push(i);
        }
        while(!st.empty()){
            int ind = n;
            int el = heights[st.top()];
            st.pop();
            int pes = st.empty()?-1:st.top();
            ans =max(ans,el*(ind-pes-1));
        }
        return ans;
    }
};