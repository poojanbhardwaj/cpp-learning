class Solution {
public:

 int f(vector<int> &prices,int i,int buy,vector<vector<int>> &dp,int fee){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(-prices[i] +f(prices,i+1,0,dp,fee),f(prices,i+1,1,dp,fee));
        }
        return dp[i][buy] = max(prices[i]-fee + f(prices,i+1,1,dp,fee),f(prices,i+1,0,dp,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
         vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(prices,0,1,dp,fee);
    }
};