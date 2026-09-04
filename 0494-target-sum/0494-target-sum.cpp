class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
         int n = arr.size();
        int total = 0;
        for(int i: arr) total+=i;
        if(total < diff) return 0;
        if((total - diff)&1) return 0; 
        int ts = (total - diff)/2;
        
        vector<vector<int>> dp(n+1,vector<int> (ts+1));
        
        for(int j = 0;j<=ts;j++){
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=ts;j++){
                if(arr[i-1] <= j) dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][ts];
    }
};