class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[i] > nums[st.top()]) {

                int bottom = st.top();
                st.pop();

                // no left boundary
                if(st.empty()) break;

                int left = st.top();

                int width = i - left - 1;
                int height = min(nums[left], nums[i]) - nums[bottom];

                ans += width * height;
            }

            st.push(i);
        }

        return ans;
    }
};