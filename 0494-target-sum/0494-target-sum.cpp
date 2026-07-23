class Solution {

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        
        for(int i:nums) sum+=i;
        if (abs(target) > sum || (sum + target) % 2 != 0)
            return 0;
        int rs = (sum+target)/2;
        vector<vector<int>> dp(n+1,vector<int> (rs+1,0));
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<rs+1;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;

            }
        }
       
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<rs+1;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else dp[i][j]= dp[i-1][j];
            }
        }
        return dp[n][rs];
    }
};