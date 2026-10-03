class Solution {
public:
vector<int> pse(vector<int> &heights){
        int n = heights.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++){ 
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int> &heights){
        int n = heights.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){ 
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<int>st;
        int ans = 0;
        vector<int> narr = nse(heights);
        vector<int> parr = pse(heights);
        int maxi = 0;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,heights[i]*(narr[i] - parr[i] -1));
        }
        return maxi;
    }
};