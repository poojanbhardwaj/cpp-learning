class Solution {
public:
int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
       vector<int> temp1(n,-1),temp2(n,n);

        stack<int> st1,st2;
        for(int i = 0;i<n;i++){
            
            while(!st1.empty() && nums[st1.top()] > nums[i]){
                
                st1.pop();
            }
            if(!st1.empty()) temp1[i] = st1.top();
            st1.push(i);
        }
         for(int i = n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()] >= nums[i]){
                
                st2.pop();
            } if(!st2.empty()) temp2[i] = st2.top();
            st2.push(i);
        }
        for(int i = 0;i<n;i++){
            long long  left  = i - temp1[i];
            long long  right = (temp2[i]-i);
            
            long long occ = left*right;
            ans += (occ*nums[i])%mod;
        }
    return ans%mod;
    }
};