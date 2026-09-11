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
        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i = 1;i<n;i++){
            if(nums[i] > dp.back()) dp.push_back(nums[i]);
            else{
                int idx = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        return dp.size();
    }
};