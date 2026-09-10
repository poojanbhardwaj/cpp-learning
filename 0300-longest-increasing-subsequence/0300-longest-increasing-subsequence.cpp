class Solution {
public:
    int f(vector<int>& nums, int i, vector<int>& dp) {
        if(dp[i] != -1) return dp[i];

        int ans = 1;  // nums[i] itself

        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] > nums[i]) {
                ans = max(ans, 1 + f(nums, j, dp));
            }
        }

        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(ans, f(nums, i, dp));
        }

        return ans;
    }
};