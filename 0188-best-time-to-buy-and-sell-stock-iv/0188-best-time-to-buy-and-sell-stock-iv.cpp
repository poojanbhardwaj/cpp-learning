class Solution {
public:
    int f(int i,int k,int buy,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i ==prices.size() || k == 0) return 0;
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        if(buy){
            return dp[i][k][buy] = max(-prices[i]+f(i+1,k,0,prices,dp),f(i+1,k,1,prices,dp));

        }
        return dp[i][k][buy] = max(prices[i]+f(i+1,k-1,1,prices,dp),f(i+1,k,0,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (k+1,vector<int> (2,-1)));
        return f(0,k,1,prices,dp);
    }
};