class Solution {
public:
    int f(vector<int> &nums,int i,int prev,vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int nt = f(nums,i+1,prev,dp);
        if(prev == -1 || nums[i] > nums[prev]) return dp[i][prev+1] = max(nt,1+f(nums,i+1,i,dp));
        return dp[i][prev+1] = nt;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return f(nums,0,-1,dp);
    }
};