class Solution {
public:
    int f(int i,vector<int> & costs,int n,vector<int>&dp){
        if(i == n-1) return 0;
        if(dp[i+1] != -1) return dp[i+1];
        int a = INT_MAX/2;
        if(i+1<n){
            a = f(i+1,costs,n,dp) + 1 + costs[i+1];
        } 
        int b = INT_MAX/2;
        if(i+2<n){
            b  =f(i+2,costs,n,dp) + 4 + costs[i+2];
        }
        int c = INT_MAX/2;
        if(i+3<n){
            c = f(i+3,costs,n,dp) + 9 + costs[i+3];
        }
    return dp[i+1] = min(a,min(b,c));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return f(-1,costs,n,dp);
    }
};