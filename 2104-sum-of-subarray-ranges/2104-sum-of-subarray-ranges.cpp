class Solution {
public:
    long long sumax(vector<int> &nums){  int n = nums.size();
        vector<int> prev(n,-1);

        vector<int> next(n,n);
        stack<int> st1,st2;
        for(int i = 0;i<n;i++){
            while(!st1.empty() && nums[st1.top()] <= nums[i]){
                st1.pop();

            }
            if(!st1.empty()) prev[i] = st1.top();
            st1.push(i);
        }
         for(int i = n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()] < nums[i]){
                st2.pop();

            }
            if(!st2.empty()) next[i] = st2.top();
            st2.push(i);
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int l = i-prev[i];
            int r = next[i] - i;
            long long occ= l*r;
            ans += occ*1LL*nums[i];
        }
        return ans;
    }
    long long summin(vector<int>&nums){
        int n = nums.size();
        vector<int> prev(n,-1);

        vector<int> next(n,n);
        stack<int> st1,st2;
        for(int i = 0;i<n;i++){
            while(!st1.empty() && nums[st1.top()] >= nums[i]){
                st1.pop();

            }
            if(!st1.empty()) prev[i] = st1.top();
            st1.push(i);
        }
         for(int i = n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()] > nums[i]){
                st2.pop();

            }
            if(!st2.empty()) next[i] = st2.top();
            st2.push(i);
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int l = i-prev[i];
            int r = next[i] - i;
            long long occ= l*r;
            ans += occ*1LL*nums[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        return sumax(nums) - summin(nums);
        
    }
};