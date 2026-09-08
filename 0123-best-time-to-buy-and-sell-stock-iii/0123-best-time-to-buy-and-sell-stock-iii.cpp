class Solution {
public:
    int f(int i,int k,int buy,vector<int> &prices,int n, vector<vector<vector<int>>> &dp){
        if(i == n || k == 0) return 0;
        if(dp[i][k][buy] != -1)return dp[i][k][buy];
        if(buy){
            return dp[i][k][buy] = max(-prices[i] + f(i+1,k,0,prices,n,dp),f(i+1,k,1,prices,n,dp));
        }
        
        return dp[i][k][buy] =max(prices[i] + f(i+1,k-1,1,prices,n,dp),f(i+1,k,0,prices,n,dp));
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int> (2,-1)));
        return f(0,2,1,prices,n,dp);
                
    } 
};